set(COMPONENT_SRCS "m5stickc-mrubyc-template")
set(COMPONENT_ADD_INCLUDEDIRS ".")

idf_component_register(SRCS "ble_client.c" INCLUDE_DIRS ".")
register_component()
