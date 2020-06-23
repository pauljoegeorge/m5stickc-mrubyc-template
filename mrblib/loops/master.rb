greet = Greet.new
while true
  # puts greet.hola
  if button_a_pressed?
    puts "Button A pressed"
    puts_tft(0, 30, 160, 100, "RED");
  end
  if button_b_pressed?
    puts "Button B pressed"
    puts_tft(0, 30, 160, 100, "GREEN");
  end
  sleep 0.3
end
