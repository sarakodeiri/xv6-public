#include "types.h"
#include "stat.h"
#include "user.h" 

int main(void)
{  
    struct proc_info {
    int pid ;
    int memsize ;
    };

    mysyscall();
    printf(1, "My first xv6 program\n");  
    return 0;
}   