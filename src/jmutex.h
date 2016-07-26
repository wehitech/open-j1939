/*
 * jmutex.h mutex head file.
 * author: Stevin Liang <stevin_liang@163.com>
 *
 *   This file is released under GPLv2
 **/

#ifndef _JMUTEX_H
#define _JMUTEX_H

struct jmutex
{
	int count;
};

extern void jmutex_init(struct jmutex *lock, int locked);

extern void jmutex_lock(struct jmutex *lock);

extern void jmutex_unlock(struct jmutex *lock);

#endif
