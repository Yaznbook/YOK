#ifndef YOK_PROCESS_H
#define YOK_PROCESS_H

#include "yok_thread.h"

typedef struct yok_process {
    int pid;
    yok_thread_t* main_thread;
} yok_process_t;

yok_process_t* yok_process_create(const char* name);

#endif // YOK_PROCESS_H
