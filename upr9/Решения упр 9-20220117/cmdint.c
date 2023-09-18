#include <stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#define	YES	1
#define	NO	0
#define	MAXLINE	80
#define	MAXARG	10

char	*arg[MAXARG],  com[MAXLINE];

main()
{
  int  k, pid;

	write(1,"COM>",4);
	while (  ( k = input_l () ) >= 0 ) {
	   if (k)  {
	      if (( pid = fork() ) < 0 ) { write(2,"Cannot fork\n",12); exit(0); }
	      else {
		    if ( pid != 0 ) wait();
		    else  {
		 		execvp(arg[0],arg);
				write(1,"cannot exec ",12);
				write(1,arg[0],10);
				exit(1);
		      	  }
		   }
	   }
	   write(1,"COM>",4);
	}   /*  while  */
}

int input_l ()  {
int i, j, nbyt, word;

	word = NO; j = 0; i = 0;
	while  ( ( nbyt = read(0, &com[j], 1) )!= 0 ) {
	 	if ( com[j] == ' ' ) {
		   if  ( word == YES ) {
			 word = NO;
			 com[j++] = '\0';
		   }
		}
		else  
		if ( com[j] != '\n' ) {
			if ( word == NO ) {
			     word = YES;
			     arg[i++] = &com[j];
			}
			++j;
		}
		else
		if ( com[j] == '\n' ) {
			if  ( word == YES ) com[j] = '\0';
		        arg[i] = NULL;
			if ( strcmp (arg[0],"logout") == 0 ) exit (0) ;
			else  return (i) ;
		}    /*  if  '\n'  */
	}  /*  while  != EOF  */
	if  ( nbyt == 0 )  exit (0);
} 
