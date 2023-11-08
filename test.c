#include <stdio.h>
extern void initialise_monitor_handles(void);
int main(int argc, char *argv[]){
    initialise_monitor_handles();
    printf("Hello World\n");
    //_write(0,"asdf\n",6);
    while(1){}
}
