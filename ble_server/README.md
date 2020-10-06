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
 
> - BLE server has one Application profile (Its possible to have multiple application profiles, but we are expecting only one M5StickC to be connected) <br>
> - BLE server has one service handle which has created one charecteristics with `READ WRITE NOTIFY` permission <br>
> - Once the BLE client is connected to BLE server, if the service UUID and charecteristics ID of BLE server is known, its possible for BLE client to read write and notify to BLE server <br>
> - In our case BLE client will connect to BLE server and write `1` when calling bell (BUTTON A ) is pressed. <br>


## Working
- Flash code to M5StickC
- Once flashed, M5StickC will enable Bluetooth and start advertising `ESP_DOOR_CHIME`
- Advertising is forever
- M5StickC will display message Advertising
- Once BLE client is connected, M5StickC display message will change from `Advertidsing` to `Paired and Adv.`
- BLE server has one Application Profile service and one characteristic `0xFF01`. whenever ble client write `1` (chime notify) to BLE server,  M5StickC will display `CHIME!` on screen. 
- Use top button (Button B) to stop/restart advertising.




## Points to remember
- Dont forget to send a reset chime signal back to the BLE client once received the notificaiton
  - https://github.com/pauljoegeorge/m5stickc-mrubyc-template/blob/d7d8a02d6cf6b755a7f35a675d1b9535dd944afa/ble_server/mrblib/loops/master.rb#L26
  - feel free to move this to model if needed. 
  
