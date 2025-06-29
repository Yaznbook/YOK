#include <stdio.h>
#include <stddef.h> // NULL
#include "yok_scheduler.h"

#define MAX_THREADS 10

static yok_thread_t* thread_list[MAX_THREADS];
static int thread_count = 0;
static int current_index = -1;

void yok_scheduler_add_thread(yok_thread_t* t) {
    if (thread_count < MAX_THREADS) {
        thread_list[thread_count++] = t;
    }
}

void yok_scheduler_init() {
//    printf("[YOK] Scheduler initialized\n");
    thread_count = 0;
    current_index = -1;
}

yok_thread_t* yok_scheduler_pick() {
    if (thread_count == 0) return NULL;

    current_index = (current_index + 1) % thread_count;
    return thread_list[current_index];
}

void yok_scheduler_run() {
    if (thread_count == 0) {
  //      printf("[YOK] No threads to schedule\n");
        return;
    }

    yok_thread_t* next = yok_scheduler_pick();
  //  printf("[YOK] 🧵 Switching to thread %d\n", next->tid);
    yok_thread_switch(next);
}
