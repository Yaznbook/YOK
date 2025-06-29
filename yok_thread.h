#ifndef YOK_THREAD_H
#define YOK_THREAD_H

struct yok_process; // Forward declaration

typedef struct yok_thread {
    int tid;
    struct yok_process* owner;
    void (*run)(struct yok_thread*);  // تضيف مؤشر دالة run
} yok_thread_t;

yok_thread_t* yok_thread_create(struct yok_process* owner);
void yok_thread_run(yok_thread_t* t);
void yok_thread_switch(yok_thread_t* t);

#endif // YOK_THREAD_H
