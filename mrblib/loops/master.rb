greet = Greet.new
ble = BleClient.new

while true

  # chime on click
  if button_a_pressed?
    puts "Button A pressed"
    put_color(0, 30, 160, 100, "RED");
    put_string(60, 60, "BUTTON A");
    if ble.paired?
      send_chime_notification
    end
  end
  
  # for scanning and disconnecting
  if button_b_pressed?
    puts "Button B pressed"
    put_color(0, 30, 160, 100, "GREEN");
    put_string(60, 60, "BUTTON B");
    if ble.paired?
      ble.disconnect
      put_string(60, 60, "Disconnected..");
    else
      ble.restart_scanning # for 30 seconds
      scan_duration = 0
      while(scan_duration < 30 || !ble.paired?)
        put_string(60, 60, "Pairing..");
        scan_duration = scan_duration + 1;
        sleep(1)
      end
      if(ble.paired?)
        put_string(60, 60, "Connected..");
      else
        put_string(60, 60, "Pairing X");
      end
    end
  end

  sleep 3
end
