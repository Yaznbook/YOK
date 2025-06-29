.section .multiboot
.align 4
.long 0x1BADB002                 # magic number
.long 0x00                      # flags (مثلاً 0)
.long -(0x1BADB002 + 0x00)     # checksum

