#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
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
/**

 * Brief:
 * This test code shows how to configure gpio and how to use gpio interrupt.
 *
 * GPIO status:
 * GPIO18: output
 * GPIO19: output
 * GPIO4:  input, pulled up, interrupt from rising edge and falling edge
 * GPIO5:  input, pulled up, interrupt from rising edge.
 *
 * Test:
 * Connect GPIO18 with GPIO4
 * Connect GPIO19 with GPIO5
 * Generate pulses on GPIO18/19, that triggers interrupt on GPIO4/5
 *
 */


#define MEMORY_SIZE (1024*40)

static uint8_t memory_pool[MEMORY_SIZE];

#define GPIO_OUTPUT_IO_0    26
// #define GPIO_OUTPUT_IO_1    19
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<GPIO_OUTPUT_IO_0))
#define GPIO_INPUT_IO_0     36
// #define GPIO_INPUT_IO_1     5
#define GPIO_INPUT_PIN_SEL  ((1ULL<<GPIO_INPUT_IO_0))
#define ESP_INTR_FLAG_DEFAULT 0

static xQueueHandle gpio_evt_queue = NULL;

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
