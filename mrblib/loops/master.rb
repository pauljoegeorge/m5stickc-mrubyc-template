greet = Greet.new
ble = BleClient.new

while true

  # chime on click
  if button_a_pressed?
    # puts "Button A pressed"
    put_color(0, 30, 160, 100, "RED");
    put_string(60, 60, "BUTTON A");
    if ble.paired?
      send_chime_notification
    end
  end
  
  # for scanning and disconnecting
  if button_b_pressed?
    # puts "Button B pressed"
    put_color(0, 30, 160, 100, "GREEN");
    put_string(60, 60, "BUTTON B");
    if ble.paired?
      ble.disconnect
      put_string(60, 60, "Disconnected..");
    else
      ble.restart_scanning # for 10 seconds
      put_string(60, 60, "Pairing..");
    end
  end

  if !(button_a_pressed? && button_b_pressed?) && ble.paired?
    put_color(0, 30, 160, 100, "RED");
    put_string(60, 60, "Paired..");
  end

  sleep 3
end
