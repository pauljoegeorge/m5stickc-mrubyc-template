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

	def stop_advertising
		ble_stop_advertising
	end

	def restart_advertising
		ble_restart_advertising
	end
end
