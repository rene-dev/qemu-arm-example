ENTRY(interrupt_reset)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x0000000, LENGTH = 128k
    RAM (rw) : ORIGIN = 0x20000000, LENGTH = 8k
}
 
SECTIONS
{
    .text :
    {
        KEEP(*(.vector_table))
        *(.text)
    } >FLASH
    
    .rodata :
    {
        *(.rodata.*)
    } >FLASH

    .data_flash_begin :
    {
        _DATA_FLASH_BEGIN = .;
    } >FLASH

    .data :
    {
        _DATA_RAM_BEGIN = .;
        *(.data.*)
        _DATA_RAM_END = .;
    } >RAM AT >FLASH

    .data_flash_end :
    {
        _DATA_FLASH_END = .;
    } >FLASH

    .bss :
    {
        _BSS_BEGIN = .;
        __bss_start__ = .;
        *(.bss.*)
        _BSS_END = .;
        __bss_end__ = .;
        PROVIDE ( end = . );
        PROVIDE ( _end = . );
        PROVIDE ( __end__ = . );
    } >RAM

    _stack_size = 4096;
    _stack_end = ORIGIN(RAM)+LENGTH(RAM);
    _stack_begin = _stack_end - _stack_size;
    . = _stack_begin;
    ._stack :
    {
    . = . + _stack_size;
    } > RAM
}  