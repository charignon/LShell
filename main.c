#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main ()
{

char * command = (char *) malloc (sizeof (char) * 25);
char * buffer  = (char *) malloc (sizeof (char) * 25);
int size_command = 0;
int n = 0;




printf("Welcome to LSell\n");
for(;;)
{ 
  size_command = 0;
  n = 0;
  for(;;)
  {
    n = read(1,buffer,25*sizeof(char));
    printf("************************* n  = %d *******************\n",n);
    printf("%s %s %d \n", command,buffer,size_command+n);
    command = (char*) realloc(command,(size_command+n)*sizeof(char));
    command = (char*)strncat(command,buffer,sizeof(char)*n);
    size_command+=n;
    if (n < 25 || buffer[24]=='\n')
      break;
  }
  break;
}

free(buffer);
free(command);



return EXIT_SUCCESS;




}
