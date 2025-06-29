#include <stdio.h>
#include <stdlib.h>
#include "yok_thread.h"
#include "yok_process.h"   // ضروري لتعريف struct yok_process كامل
#include "yok_memory.h"

static int global_tid = 1;

yok_thread_t* yok_thread_create(struct yok_process* owner) {
    yok_thread_t* t = (yok_thread_t*) yok_malloc(sizeof(yok_thread_t));
    t->tid = global_tid++;
    t->owner = owner;
    return t;
}

void yok_thread_run(yok_thread_t* t) {
//    printf("[YOK] 🧵 Running thread %d of process %d\n", t->tid, t->owner->pid);
}

void yok_thread_switch(yok_thread_t* t) {
  //  printf("[YOK] 🔁 Context switched to thread %d\n", t->tid);
}
