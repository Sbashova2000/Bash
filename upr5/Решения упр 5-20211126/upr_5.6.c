#include <stdio.h>


main(argc,argv)
int argc;
char *argv[];
{
   int rc =0;

   if (execvp(argv[1],&argv[1]) == -1) {
      printf("\nERROR\n");
      rc = 1;
   }
    else {
       printf("This line is never printed\n");
    }
    exit(rc);
}
