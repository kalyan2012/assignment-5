Waitx syscall:
    Added waitx syscall function to proc.c
    This function does same work as Wait but extra returns the wait time and run time for the child in the parameters wtime, rtime.
    type time in qemu-nox which displays the wait time and run time of the created child process in time.c.
    Changes are done to def.h, user.h, usys.S, syscall.c, syscall.h, Makefile, sysproc.c, trap.c.

Scheduling:
    Three different Schedulers are added to the proc.c file namely, FCFS, MLFQ, PBS, with given RR.
FCFS:
    Iterate through the table to find the process with least creation time (ctime) and execute it.
    ctime is given to process during allocation of process.
PBS:
    The process with highest priority is executed first.
    From the process table find the process with least numbered priority and execute it.
    Priority is changed using setPriority command.
    While setting the priority of a process yield the process if the changed priority is less than previous one and running them in RR manner.
MLFQ:
    There are 5 queues for process. All runnable process are stored here. As soon as a process is entered it is added to the first queue (q0),
    There are two function add and remove to add and remove a process from a queue basing on a flag assigned to each process.
    A process is shifted from queue if it takes time beyond the time quantum and is put in next queue if it is completed it exits the queue.
    If a process is in q4 it is not further degraded and is executed.
    Aging is done for a process if it waits for more than a particular time i.e it is upgraded to top queue.