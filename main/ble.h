#include "mrubyc.h"
void c_ble_start_advertising(mrb_vm *vm, mrb_value *v, int argc);
void c_ble_stop_advertising(mrb_vm *vm, mrb_value *v, int argc);
void c_ble_restart_advertising(mrb_vm *vm, mrb_value *v, int argc);
void c_ble_advertising(mrb_vm *vm, mrb_value *v, int argc);
void c_ble_initialize(mrb_vm *vm, mrb_value *v, int argc);
void c_chime_rang(mrb_vm *vm, mrb_value *v, int argc);
void c_pairing_status(mrb_vm *vm, mrb_value *v, int argc);
void c_reset_chime_rang(mrb_vm *vm, mrb_value *v, int argc);