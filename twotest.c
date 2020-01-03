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
        setpriority(67);
        printf(1,"THIS SHOULDNT PRINT %d\n");
        exit();
    }

    else if (p1 == 0 && p2 == 0 && p3 != 0){
        
        int temp = 0;
        setpriority(89);
        printf(1,"FIRST: Priority 89 \t Pid: %d\n",getpid());

        for (int i = 0; i < 300000; i++)
            temp++;
        
        exit();
	}
	else if (p1 == 0 && p2 != 0 && p3 == 0){
        
        int temp = 0;
        setpriority(20);
        printf(1,"SECOND: Priority 20 \t Pid: %d\n",getpid());
        
        for (int i = 0; i < 300000; i++)
            temp++;
        
        exit();
	}

    else if (p1 != 0 && p2 == 0 && p3 == 0){
        
        int temp = 0;
        setpriority(51);
        printf(1,"THIRD: Priority 51 \t Pid: %d\n",getpid());

        
        for (int i = 0; i < 300000; i++)
            temp++;
        
        exit();
	}

	else if ((p1 && p2 && p3) != 0){ // Parent
        cps();
        sleep(100);
        cps();
        wait();
        exit();
	}
    exit();
}
