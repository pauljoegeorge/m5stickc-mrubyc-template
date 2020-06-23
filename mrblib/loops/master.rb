greet = Greet.new
while true
  # puts greet.hola
  puts "Button A pressed" if button_a_pressed?
  puts "Button B pressed" if button_b_pressed?
  sleep 0.3
end
