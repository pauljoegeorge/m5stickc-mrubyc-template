class BleClient
	def initialize
		if !ble_paired?
			ble_initialize
			ble_init_scanning
		end
	end	

	def paired?
		ble_paired?
	end

	def restart_scanning
		ble_restart_scanning # 5 seconds
	end

	def disconnect
		ble_disconnect
	end

	def scanning?
		ble_scanning?
	end
end