#include "yok_serial.h"

// عشان تستخدم inb, outb تحتاج تعريفهم أو تكتبهم بنفسك
static inline unsigned char inb(unsigned short port) {
    unsigned char ret;
    __asm__ volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

static inline void outb(unsigned short port, unsigned char val) {
    __asm__ volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

#define SERIAL_PORT 0x3F8

void serial_write_char(char c) {
    while ((inb(SERIAL_PORT + 5) & 0x20) == 0);
    outb(SERIAL_PORT, c);
}

void serial_write_string(const char* s) {
    while (*s) {
        serial_write_char(*s++);
    }
}
