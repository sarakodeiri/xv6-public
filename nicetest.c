#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
    int pid = fork();

    
    if(pid > 0){
        cps();
        sleep(100);
        // cps();
        wait();
        // cps();
        exit();
    }

    else if (pid == 0){
        
        int temp = 0;
        nice(getpid(), 1);
        printf(1,"FIRST: Priority 89 \t Pid: %d\n",getpid());
        
        cps();

        for (int i = 0; i < 10000; i++)
            temp++;
        
        exit();
	}
	
    exit();
}
