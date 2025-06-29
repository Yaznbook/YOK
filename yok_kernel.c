// yok_kernel.c
#include "yok_kernel.h"
#include "yok_memory.h"
#include "yok_scheduler.h"
#include "yok_process.h"
#include "yok_thread.h"
#include "yok_serial.h"  // لو تستخدم دوال طباعة للسيريال

// دوال منخفضة المستوى لقراءة وكتابة في بورتات I/O (مثلاً للـ serial)
unsigned char inb(unsigned short port) {
    unsigned char ret;
    __asm__ volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

void outb(unsigned short port, unsigned char val) {
    __asm__ volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

// تابع لكتابة بايت على السيريال (هذا هنا مجرد مثال، الأفضل تعرفها في yok_serial.c)
void serial_write_byte(char c) {
    while ((inb(0x3F8 + 5) & 0x20) == 0); // انتظار جاهزية البورت
    outb(0x3F8, c);
}

// فقط إعلان بدون تعريف (تعريفها في yok_serial.c)
void serial_write_string(const char* str);

void yok_boot() {
    //printf("[YOK] 🔥 Booting Yaznbook OS Kernel...\n");
        serial_write_string("Welcome to YOK (Yaznbook OS Kernel)");
    yok_memory_init();
    yok_scheduler_init();

    yok_process_t* init_proc = yok_process_create("init");
    yok_scheduler_add_thread(init_proc->main_thread);
    yok_thread_run(init_proc->main_thread);

    //printf("[YOK] ✅ Kernel initialized. Ready to schedule.\n");
   
    while(1) {
        yok_scheduler_run();
    }
}
