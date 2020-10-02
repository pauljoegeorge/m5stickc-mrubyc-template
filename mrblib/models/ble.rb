class Ble
	def initialize
		if !ble_paired?
			ble_initialize
			ble_start_advertising
		end
	end

	def paired?
		ble_paired?
	end

	def chime_rang?
		ble_chime_rang?
	end

	def reset_chime
		ble_set_signal_low
	end
end
