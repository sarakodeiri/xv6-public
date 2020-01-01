#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc,char *argv[])
{
  int w, r, pid;
  pid = fork();
  if (pid == 0){
    // sleep(500);
    for (int i=0; i<1000; i++){
        printf(1, "1 sacsd");
    }
      // printf(1, "1 ");
  }


  else if (pid > 0){
    waitx(&w, &r);
    printf(1, "Wtime: %d Rtime: %d\n", w, r);
  }
  
  exit();
}