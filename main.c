#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>

int main ()
{

char * command = (char *) malloc (sizeof (char) * 25);
char * buffer  = (char *) malloc (sizeof (char) * 25);
char * args []= {"ls",NULL};
int size_command = 0;
int n = 0;
int pid ;


printf("Welcome to LSell\n");
for(;;)
{ 
  size_command = 0;
  n = 0;
  for(;;)
  {
    n = read(1,buffer,25*sizeof(char));
    command = (char*) realloc(command,(size_command+n)*sizeof(char));
    command = (char*)strncat(command,buffer,sizeof(char)*n);
    size_command+=n;

    if (n < 25 || buffer[24]=='\n')
      break;
  }
  //We have a command to execute
  printf("%s\n",command); 
  command[size_command-1]='\0';
  switch(pid = fork())
  {
  case -1 : perror("fork");break;
        
  case 0 : 
            execvp(command,args);
            break;
  default : wait(0);break;
  }

  break;
}

free(buffer);
free(command);

return EXIT_SUCCESS;




}
