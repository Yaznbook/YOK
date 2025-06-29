#include <stdio.h>
#include <stdlib.h>
#include "yok_process.h"
#include "yok_thread.h"
#include "yok_memory.h"


static int global_pid = 1;

yok_process_t* yok_process_create(const char* name) {
    yok_process_t* p = (yok_process_t*) yok_malloc(sizeof(yok_process_t));
    p->pid = global_pid++;
    p->main_thread = yok_thread_create(p);
//    printf("[YOK] 👤 Created process '%s' with PID %d\n", name, p->pid);
    return p;
}
