YOK (Yaznbook OS Kernel)
YOK is a simple, educational operating system kernel developed by Yaznbook Company. It is a lightweight 32-bit kernel designed for learning OS internals, kernel development, and experimenting with process/thread management, memory handling, and scheduling.

Features
Basic memory management subsystem

Simple process and thread creation

Cooperative thread scheduler

Serial output for debugging and kernel messages

Multiboot compliant for bootloader support

Prerequisites
GCC with -m32 support (for 32-bit compilation)

ld linker

qemu emulator

NASM (for assembling multiboot header, if used)

Building YOK Kernel
Compile all C source files and assemble any required assembly files (like multiboot header):

```
gcc -m32 -ffreestanding -c main.c -o main.o
gcc -m32 -ffreestanding -c yok_kernel.c -o yok_kernel.o
gcc -m32 -ffreestanding -c yok_memory.c -o yok_memory.o
gcc -m32 -ffreestanding -c yok_process.c -o yok_process.o
gcc -m32 -ffreestanding -c yok_thread.c -o yok_thread.o
gcc -m32 -ffreestanding -c yok_scheduler.c -o yok_scheduler.o
gcc -m32 -ffreestanding -c yok_serial.c -o yok_serial.o
gcc -m32 -ffreestanding -c yok_utils.c -o yok_utils.o
gcc -m32 -ffreestanding -c multiboot_header.S -o multiboot_header.o
```
Link all object files into a kernel binary:

```
ld -m elf_i386 -T linker.ld -nostdlib --entry _start -o kernel.bin \
main.o yok_kernel.o yok_memory.o yok_process.o yok_thread.o \
yok_scheduler.o yok_serial.o yok_utils.o multiboot_header.o```

Running YOK Kernel in QEMU
Launch the kernel using QEMU with serial output redirected to your terminal:

```
qemu-system-i386 -kernel kernel.bin -serial stdio -no-reboot
```

This will start the kernel in an emulator window, and all kernel output will be displayed in your terminal.

About Yaznbook Company
Yaznbook Company is dedicated to building open-source educational software projects to empower young developers and enthusiasts to learn system programming, OS design, and kernel development.

Contributing
Feel free to contribute to YOK kernel by submitting issues, pull requests, or improving documentation.

License
This project is licensed under the ISC License.
