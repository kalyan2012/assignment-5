#include "types.h"
#include "user.h"

int number_of_processes = 10;

int main(int argc, char *argv[])
{
  int j;
  int start_time  = uptime();
  for (j = 0; j < number_of_processes; j++)
  {
    int pid = fork();
    if (pid < 0)
    {
      printf(1, "Fork failed\n");
      continue;
    }
    if (pid == 0)
    {
      volatile int i;
      for (volatile int k = 0; k < number_of_processes; k++)
      {
        if (k <= j)
        {
          sleep(200); //io time
        }
        else
        {
          for (i = 0; i < 100000000; i++)
          {
            ; //cpu time
          }
        }
      }
      //printf(1, "Process: %d Finished\n", j);
      exit();
    }
    else
    {
        set_priority(100-(20+j),pid); // will only matter for PBS, comment it out if not implemented yet (better priorty for more IO intensive jobs)
    }
  }
  for (j = 0; j < number_of_processes; j++)
  {
    int *wtime;
    int *rtime;
    int pid;
    wtime = (int *) malloc(sizeof(int));
    rtime = (int *) malloc(sizeof(int));
    pid = 0;
    pid += 1;
    pid = waitx(wtime,rtime);
    printf(1,"%d: ",pid);
    printf(1,"wait time: %d total time: %d\n ",*wtime,*rtime);
    printf(1,"sfsfsf");
  }
  printf(1,"\n");
  int end_time  = uptime();
  printf(1, " Total run time: %d\n", end_time-start_time);
  exit();
}