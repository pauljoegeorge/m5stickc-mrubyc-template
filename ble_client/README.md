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

