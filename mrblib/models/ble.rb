class Ble
	def initialize
		if !ble_paired?
			ble_initialize
			ble_start_advertising
		end
	end
end
