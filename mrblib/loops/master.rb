greet = Greet.new
ble = Ble.new

while true
  # puts greet.hola
  # if button_a_pressed?
  #   puts "Button A pressed"
  #   put_color(0, 30, 160, 100, "RED");
  #   put_string(60, 60, "BUTTON A");
  # end
  # if button_b_pressed?
  #   puts "Button B pressed"
  #   put_color(0, 30, 160, 100, "GREEN");
  #   put_string(60, 60, "BUTTON B");
  # end

  if ble.paired?
    puts "paired.."
    send_chime_notification
  end
  sleep 3
end
