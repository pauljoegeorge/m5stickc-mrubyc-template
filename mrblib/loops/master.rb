greet = Greet.new
ble = Ble.new
while true
  # puts greet.hola
  if button_a_pressed?
    puts "Button A pressed"
    put_color(0, 30, 160, 100, "RED");
    put_string(60, 60, "BUTTON A");
  end
  if button_b_pressed?
    puts "Button B pressed"
    put_color(0, 30, 160, 100, "GREEN");
    if ble.paired?
      ble.stop_advertising
      put_string(60, 60, "STOP ADV.");
    else
      ble.restart_advertising
      put_string(60, 60, "START ADV.");
    end
  end
  if ble.paired?
    if  ble.chime_rang?
      put_color(0, 30, 160, 100, "BLUE")
      put_string(60, 60, "CHIME !!")
      sleep(1)
      ble.reset_chime
    end
  else
    if !(button_a_pressed? && button_b_pressed?) && ble.advertising?
      put_color(0, 30, 160, 100, "RED");
      put_string(60, 60, "Advertising");
    else
      put_color(0, 30, 160, 100, "RED");
      put_string(60, 60, "Stopped Advertising");
    end
  end
  sleep 0.3
end
