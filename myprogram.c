#include "types.h"
#include "stat.h"
#include "user.h" 
#define NPROC 64

int main(void)
{  
    struct proc_info {
    int pid ;
    int memsize ;
    };

    struct proc_info *passed_list = malloc(64 * sizeof(struct proc_info));
    int fres = fork();
    
    if (fres == 0){
        for (int i=0; i<1000; i++){
            int *blah = malloc(13 * sizeof(char *));
            *blah = 1;
        }
    }
    else if (fres > 0){
        int rc = fork();

        if (rc == 0){
            for (int i=0; i<100000; i++){
            int *blah = malloc(47 * sizeof(char *));
            *blah = 1;
        }
        }

        if(rc > 0){
                mysyscall(passed_list);
            for (int i=0; i<NPROC; i++){

            if ( ((passed_list+i) -> pid != 0) && ((passed_list+i) -> memsize != 0) ){
                printf(1, "IN MYPROGRAM PID %d\n", (passed_list+i) -> pid);
                printf(1, "IN MYPROGRAM MEMSIZE %d\n", (passed_list+i) -> memsize);
            }

            }
        }
        
    }
    
    exit();
}   