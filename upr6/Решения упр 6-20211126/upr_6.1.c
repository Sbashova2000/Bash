#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>

main ( )
{
   int pid1,pid2,pid;
   pid=fork();
   if ( pid==0)
   {  
      pid1=fork();
      // pid2=fork();
      if ( pid1==0);
      {
         fork();
      }       
   }
   printf("pid= %d ppid=%d\n", getpid(),getppid());
   wait(NULL); wait(NULL); wait( NULL);
}  
