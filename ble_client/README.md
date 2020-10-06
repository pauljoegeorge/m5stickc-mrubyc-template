# mruby/c template for M5StickC
 - This  is a template to start using mruby/c on M5StickC

# For environment setup related information:
  - check here: https://github.com/pauljoegeorge/Esp32-dev-on-Docker


# Info:

> - BLE client will enable bluetooth and connect to device with name `ESP_DOOR_CHIME`
> - BLE client knows the service UUID and charecteristics ID of BLE server. 
> - BLE client will initiate NOTIFY and write to charecteristics whenever door bell is pushed (BUTTON A)


## Working 
- Flash code to M5StickC
- Once flashed:
  - M5StickC will `enable Bluetooth` and start looking for BLE server with device name `ESP_DOOR_CHIME`
  - you can change the device name by changing in `main/main.c`
  - M5StickC will display message `pairing` until connected to BLE server
  - scanning for BLE advertiser is set to `forever`. You can change it  line `500` and `323` (code is not optimized :|)
  - Once paired, M5StickC will display message `Paired`
  - Click on Square button(BUTTON A) is the calling bell. click on it to send signal to BLE Advertiser. 
   - You will notice message `CHIME!` displayed on BLE server. 
  - Click on TOP button (BUTTON B) to to pair/disconnect BLE
  
  
  
