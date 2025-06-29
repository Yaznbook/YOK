// yok_utils.c
#include <stdint.h>

void vga_print(const char* str) {
    volatile char* video = (volatile char*) 0xB8000;
    while (*str) {
        *video++ = *str++;   // الحرف
        *video++ = 0x07;     // اللون (رمادي على أسود)
    }
}
