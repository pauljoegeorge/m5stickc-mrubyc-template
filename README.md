# mruby/c template for M5StickC
 - This  is a template to start using mruby/c on M5StickC

# For environment setup related information:
  - check here: https://github.com/pauljoegeorge/Esp32-dev-on-Docker



# BLE

## GATT server
 - Placed inside the house (maybe used as a watch)
 
## GATT client
 - Placed outside the door (when a guest comes, guest will click button which is CHIME!!)
 
 
 
## Workflow 

- Flash BLE server to one M5StickC
  - Will start advertising ( BLE name is set to ESP_DOOR_CHIME)
- Flash BLE server to another M5StickC
  - will start searching (for ESP_DOOR_CHIME)
- BLE server & BLE client will be paired
- Click on square button ``(Button A)`` of BLE client to send chime notification
  - on BLE server you will see a message CHIME in blue color
- click on top button `(Button B)` of BLE_SERVER to disconnect / restart pairing
- click on top button `(Button B)` of BLE_CLIENT to disconnect / restart pairing





## features available for gatt server
- ENABLE BLE
- START ADVERTISING 
- CONNECT TO BLE CLIENT
- CHECK PAIRING STATUS
- RECEIVE CHIME NOTIFICATION FOR BLE CLIENT
- DISCONNECT BLE_CLIENT
- RESTART SCANNING 



## features available for gatt client
- ENABLE BLE
- START SCANNING
- CONNECT TO BLE SERVER
- CHECK PAIRING STATUS
- SEND CHIME NOTIFICATION TO BLE SERVER
- DISCONNECT/RECONNECT PAIRING



