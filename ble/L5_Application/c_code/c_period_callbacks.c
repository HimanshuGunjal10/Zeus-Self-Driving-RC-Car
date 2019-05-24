/**
 * @file
 *
 * The purpose of this "C" callbacks is to provide the code to be able
 * to call pure C functions and unit-test it in C test framework
 */
#include <stdint.h>
#include <stdbool.h>
#include "c_uart2.h"
#include "c_uart3.h"
#include "stdio.h"
#include "string.h"
#include "can.h"
#include "c_period_callbacks.h"

bool dbc_app_send_can_msg(uint32_t mid, uint8_t dlc, uint8_t bytes[8])
{
    can_msg_t can_msg = { 0 };
    can_msg.msg_id                = mid;
    can_msg.frame_fields.data_len = dlc;
    memcpy(can_msg.data.bytes, bytes, dlc);

    return CAN_tx(can1, &can_msg, 0);
}
/*******************************************************/
bool C_period_init(void) {
    CAN_init(can1, 100, 25, 25 , NULL, NULL);
    CAN_reset_bus(can1);
    CAN_bypass_filter_accept_all_msgs();
    c_uart3_init(9600,64,64);
    return true;
}

bool C_period_reg_tlm(void) {
    return true;
}

void C_period_1Hz(uint32_t count) {
    (void) count;
    parse_data();



}

void C_period_10Hz(uint32_t count) {
    (void) count;




}

void C_period_100Hz(uint32_t count) {
   // fillbuffer();
    (void) count;
}

void C_period_1000Hz(uint32_t count) {
    (void) count;
}

