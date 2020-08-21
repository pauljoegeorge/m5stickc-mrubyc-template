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
    put_string(60, 60, "BUTTON B");
  end
  if ble.paired?
    if  ble.chime_rang?
      put_color(0, 30, 160, 100, "BLUE")
      put_string(60, 60, "CHIME !!")
    end
  end
  sleep 0.3
end
