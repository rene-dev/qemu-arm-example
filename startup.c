void handler_default(void)
{
while (1)
{
//loop
}
}

void handler_default1(void){while (1);}
void handler_default2(){
    
}
void handler_default3(void){while (1);}
void handler_default4(void){while (1);}
void handler_default5(void){while (1);}
void handler_default6(void){while (1);}
void handler_default7(void){while (1);}
void handler_default8(void){while (1);}
void handler_default9(void){while (1);}

extern unsigned long _DATA_FLASH_BEGIN, _DATA_RAM_BEGIN, _DATA_RAM_END, _BSS_BEGIN, _BSS_END;
int main(void);
void interrupt_reset(void)
{
unsigned long *source;
unsigned long *destination;
// Copying data from Flash to RAM
source = &_DATA_FLASH_BEGIN;
for (destination = &_DATA_RAM_BEGIN; destination < &_DATA_RAM_END;)
{
*(destination++) = *(source++);
}
// default zero to undefined variables
for (destination = &_BSS_BEGIN; destination < &_BSS_END;)
{
*(destination++) = 0;
}
// starting main program
//_start();
main();
while (1){__asm("nop");}
}


extern unsigned long _data_flash;
extern unsigned long _data_begin;
extern unsigned long _data_end;
extern unsigned long _bss_begin;
extern unsigned long _bss_end;
extern unsigned long _stack_end;

__attribute__ ((section(".vector_table")))

void (* const table_interrupt_vector[])(void) =
{
(void *) &_stack_end, // 0 - stack
interrupt_reset, // 1
handler_default1, // 2
handler_default2, // 3
handler_default3, // 4
handler_default4, // 5
handler_default5, // 6
0, // 7
0, // 8
0, // 9
0, // 10
handler_default6, // 11
handler_default7, // 12
0, // 13
handler_default8, // 14
handler_default9, // 15
// peripherals
handler_default, // 0
handler_default, // 1
handler_default, // 2
handler_default, // 3
handler_default, // 4

handler_default, // 59
handler_default // 60
};
