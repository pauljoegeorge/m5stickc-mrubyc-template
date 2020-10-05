# mruby/c template for M5StickC
 - This  is a template to start using mruby/c on M5StickC

# For environment setup related information:
  - check here: https://github.com/pauljoegeorge/Esp32-dev-on-Docker


# Info:
### Steps
  - Git pull the latest code
  - Run `make menuconfig`
    - `enable` Bluetooth
 - Run make flash monitor
 - host name: `ESP_DOOR_CHIME`
 - Connect to `ESP_DOOR_CHIME` from BLE_CLIENT running on m5stickC
 - Once connected, whenever button on BLE client is clicked, will see `CHIME!` message displayed on server
 - Click on Button B (button on top) to to stop advertising/start adv
 
