#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
int main (int argc,char *argv[])
{

	int pid;
    int status = 0;
	int a, b;
	pid = fork();
	if (pid == 0)
  	{	
        printf(1, "Child PID is %d\n", getpid());
  		int c = 0;
        for (int i = 0; i < 1000; i++) {
			printf(1, ".");
            c++;
        }
		exit();
    }
  	else if (pid > 0)
 	{
    	status = waitx(&a, &b);
 	}  
 	printf(1, "\nWait Time = %d\nRun Time = %d\nStatus %d \n", a, b, status); 
 	exit();
}