ENTRY(_start)

SECTIONS
{
  . = 0x100000; /* تحميل الكيرنل عند 1 ميغا */
  .text : { *(.text) }
  .rodata : { *(.rodata) }
  .data : { *(.data) }
  .bss : { *(.bss COMMON) }
}
