ENTRY(_start)
SECTIONS
{
    . = 0x0;

    .ivt : {
        *(.ivt*)
    }

    . = 0x1000;

    .text : {
        *(.text*)
    }

    .rodata : {
        *(.rodata*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        *(COMMON)
        *(.bss*)
    }
}