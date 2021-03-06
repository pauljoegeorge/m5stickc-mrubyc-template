#include "mrubyc.h"
void c_ble_initialize(mrb_vm *vm, mrb_value *v, int argc);
void c_ble_start_scanning(mrb_vm *vm, mrb_value *v, int argc);
void c_restart_scanning(mrb_vm *vm, mrb_value *v, int argc);
void c_pairing_status(mrb_vm *vm, mrb_value *v, int argc);
void c_scanning_status(mrb_vm *vm, mrb_value *v, int argc);
void c_send_chime_notification(mrb_vm *vm, mrb_value *v, int argc);
void c_ble_disconnect(mrb_vm *vm, mrb_value *v, int argc);
