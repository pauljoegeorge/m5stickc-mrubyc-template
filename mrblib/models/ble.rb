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
		status = ble_chime_rang?
		ble_set_signal_low
		status
	end
end
