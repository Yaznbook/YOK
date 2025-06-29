all: yaznbook.iso

kernel.bin: multiboot_header.o main.o
    ld -m elf_i386 -T linker.ld -o kernel.bin multiboot_header.o main.o yok_kernel.o yok_memory.o yok_process.o yok_thread.o yok_scheduler.o yok_utils.o yok_serial.o

multiboot_header.o: multiboot_header.S
    gcc -m32 -ffreestanding -c multiboot_header.S -o multiboot_header.o

main.o: main.c
    gcc -m32 -ffreestanding -c main.c -o main.o

yaznbook.iso: kernel.bin
    mkdir -p iso/boot/grub
    cp kernel.bin iso/boot/
    cp grub.cfg iso/boot/grub/
    grub-mkrescue -o yaznbook.iso iso/

clean:
    rm -f *.o kernel.bin yaznbook.iso
    rm -rf iso
