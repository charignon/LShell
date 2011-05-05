#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{

char * command = (char * ) malloc ( sizeof(char) * 26);
printf("Welcome to LSell\n");
int n = read(1,command,25*sizeof(char));
printf("%s \n%d \n",command,n);
free(command);




return EXIT_SUCCESS;



}
