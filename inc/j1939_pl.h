/*
 * j1939_pl.h J1939 physical abstract layer.
 * author: Stevin Liang <stevin_liang@163.com>
 * created: Jun 25, 2016
 *
 * This file is released under GPLv2
 *
 */

#ifndef __J1939_PL_H__
#define __J1939_PL_H__

#include "jtypes.h"
#include "list.h"

struct can_frame {
	uint32_t id;
	uint8_t dlc;
	uint8_t data[8];
};

#define CAN_ADAPTER_OPEN_MASK   0x00000001
#define CAN_ADAPTER_UP_MASK     0x00000002
struct can_adapter {
	struct list_head list;
	char *name;
	int status;
	int ref;
	int id;
	int (*send) (struct can_adapter *adap, struct can_frame *frame);
	int (*recv) (struct can_adapter *adap, struct can_frame *frame);
	int (*open) (struct can_adapter *adap);
	int (*close) (struct can_adapter *adap);
	int (*up) (struct can_adapter *adap);
	int (*down) (struct can_adapter *adap);
};

int can_send_frame(struct can_adapter *adap, struct can_frame *frame);
int can_recv_frame(struct can_adapter *adap, struct can_frame *frame);

struct can_adapter *can_get_adapter_by_name(char *name);
struct can_adapter *can_get_adapter_by_id(int index);

int can_register_adapter(struct can_adapter *adap);
int can_unregister_adapter(struct can_adapter *adap);

int can_open_adapter(struct can_adapter *adap);
int can_close_adapter(struct can_adapter *adap);

int can_adapter_up(struct can_adapter *adap);
int can_adapter_down(struct can_adapter *adap);


#endif
