#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_spi_flash.h"
#include "nvs_flash.h"
#include "m5stickc.h"
#include "wire.h"
#include "AXP192.h"
#include "mrubyc.h"
#include "models/greet.h"
#include "loops/master.h"

#define MEMORY_SIZE (1024*40)

static uint8_t memory_pool[MEMORY_SIZE];

//================================================================
/*! DEBUG PRINT
*/
void chip_info() {
    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
}

static void c_debugprint(struct VM *vm, mrbc_value v[], int argc){
  for( int i = 0; i < 79; i++ ) { console_putchar('='); }
  console_putchar('\n');
  chip_info();
  int total, used, free, fragment;
  mrbc_alloc_statistics( &total, &used, &free, &fragment );
  console_printf("Memory total:%d, used:%d, free:%d, fragment:%d\n", total, used, free, fragment );
  unsigned char *key = GET_STRING_ARG(1);
  unsigned char *value = GET_STRING_ARG(2);
  console_printf("%s:%s\n", key, value );
  heap_caps_print_heap_info(MALLOC_CAP_8BIT);
  heap_caps_print_heap_info(MALLOC_CAP_32BIT);
  for( int i = 0; i < 79; i++ ) { console_putchar('='); }
  console_putchar('\n');
}

void app_main(void)
{
  // FOR DISPLAY >>>M5 StickC<<<
    M5Init();
    font_rotate = 0;
    text_wrap = 0;
    font_transparent = 0;
    font_forceFixed = 0;
    gray_scale = 0;
    TFT_setGammaCurve(DEFAULT_GAMMA_CURVE);
    TFT_setRotation(LANDSCAPE);
    TFT_setFont(SMALL_FONT, NULL);
    TFT_resetclipwin();

    TFT_print(">>>M5 StickC<<<", CENTER, 0);
    vTaskDelay(500 / portTICK_PERIOD_MS);

    nvs_flash_init();
    mrbc_init(memory_pool, MEMORY_SIZE);
    mrbc_define_method(0, mrbc_class_object, "debugprint", c_debugprint);
    mrbc_create_task(greet, 0);
    mrbc_create_task(master, 0);
    mrbc_run();

}
