#include        <stdio.h>
#include        <stdlib.h>
#include        <unistd.h>

main()
{
char cmd[32];
int i = 0,p=0, status ;

while (1)
   {
        write(1,"CI>",3);
        while ( ( read ( 0 , &cmd[i] , 1) ) && cmd[i]  != '\n'  )
                {
                if ( cmd[i] == ' ' || cmd[i] == '\t') continue;
                else {if ( cmd[i] == '&') {++p;
                              cmd[i] = '\0';}
                         ++i;}
                }
        if ( cmd [i] == '\n')  cmd[i] = '\0';
        if (  strcmp(cmd,"quit")  == 0 ) exit(0) ;
        else
        {
          if (  fork() ) {
           if (!p)
            wait(&status);
           else {printf("%d\n", getpid());p--;}
            i=0;
          }
          else {
           if ( execlp(cmd,cmd,0) < 0) {
           printf("cannot execute %s\n", cmd);
           exit(1);
           }
          }
        }
   }    /*  while  */
}
