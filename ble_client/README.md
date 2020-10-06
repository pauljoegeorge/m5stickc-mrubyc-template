# mruby/c template for M5StickC
 - This  is a template to start using mruby/c on M5StickC

# For environment setup related information:
  - check here: https://github.com/pauljoegeorge/Esp32-dev-on-Docker


# Rough info:
### To test:

- Flash BLE server to one M5StickC
  - Will start advertising ( BLE name is set to ESP_DOOR_CHIME)
- Flash BLE server to another M5StickC
  - will start searching (for ESP_DOOR_CHIME)
- Click on square button (Button A) to send chime notification
   - on BLE server you will see a message CHIME in blue color
- click on top button (Button B) to disconnect / restart pairing




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
  
  
  
