#ifndef YOK_SCHEDULER_H
#define YOK_SCHEDULER_H

#include "yok_thread.h"

void yok_scheduler_init();
void yok_scheduler_run();

yok_thread_t* yok_scheduler_pick();

void yok_thread_switch(yok_thread_t* t);

#endif // YOK_SCHEDULER_H
