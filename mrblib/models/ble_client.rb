class BleClient
	def initialize
		if !ble_paired?
			ble_initialize
			ble_start_scanning
		end
	end	

	def paired?
		ble_paired?
	end
end