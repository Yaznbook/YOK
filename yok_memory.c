#include "yok_memory.h"

char yok_heap[1024 * 10];
int yok_heap_offset = 0;

void* yok_malloc(int size) {
    void* ptr = &yok_heap[yok_heap_offset];
    yok_heap_offset += size;
    return ptr;
}


void yok_memory_init() {
    // vga_print("🧠 Memory subsystem initialized\n");
}

