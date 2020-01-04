#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
    int p1,p2,p3;
    p1 = fork();
	p2 = fork();
    p3 = fork();
    
    if((p1 || p2 || p3) == 0){
        
        int temp = 0;
        setpriority(89);
        nice(getpid(),1);
        printf(1,"FIRST: Priority 89 \t Pid: %d\n",getpid());
        cps();

        for (int i = 0; i < 80000000; i++)
            temp++;
        
        exit();
    }

	else if (p1 == 0 && p2 != 0 && p3 == 0){
        
        int temp = 0;
        setpriority(20);
        nice(getpid(),3);
        printf(1,"SECOND: Priority 20 \t Pid: %d\n",getpid());
        cps();
        
        for (int i = 0; i < 80000000; i++)
            temp++;
        
        exit();
	}

    else if (p1 != 0 && p2 == 0 && p3 == 0){
        
        int temp = 0;
        setpriority(51);
        nice(getpid(),2);
        printf(1,"THIRD: Priority 51 \t Pid: %d\n",getpid());
        cps();

        
        for (int i = 0; i < 80000000; i++)
            temp++;
        
        exit();
	}

	else if ((p1 && p2 && p3) != 0){ // Parent
        int *wtime=0,*rtime=0;
        sleep(10);
        waitx(wtime,rtime);
        cps();
        waitx(wtime,rtime);
        cps();
        waitx(wtime,rtime);
        cps();
        sleep(10);
        cps();
        exit();
	}
    exit();
}
