#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc,char *argv[])
{
  int w, r, pid;
  pid = fork();
  if (pid == 0){
    sleep(50);
    for (int i=0; i<1000; i++){
        printf(1, "%d\n", i);
    }
      // printf(1, "1 ");
  }


  else if (pid > 0){
    int res = waitx(&w, &r);
    printf(1, "Wtime: %d Rtime: %d Status:%d\n", w, r, res);
  }
  
  exit();
}
