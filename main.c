#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>

int main ()
{

  char * command; char * buffer ;
  char * args []= {"ls",NULL};
  char * ret_strtok;
  int size_command = 0;
  int n = 0;
  int pid ;


  printf("Welcome to LSell\n");
  for(;;)
  { 

    //Acquire the user input
    size_command = 0;
    n = 0;
    buffer  = (char*)malloc(sizeof(char)*25);
    command = (char*)malloc(sizeof(char)*25);


    for(;;)
    {
      n = read(1,buffer,25*sizeof(char));
      command = (char*) realloc(command,(size_command+n)*sizeof(char));
      command = (char*)strncat(command,buffer,sizeof(char)*n);
      size_command+=n;

      if (n < 25 || buffer[24]=='\n')
      {
        //Remove the trailing \n
        command[size_command-1]='\0';
        break;
      }
    }

    free(buffer);


    //Parse the arguments
    ret_strtok = strtok(command," ");
    int i = 0;
    while (ret_strtok!=NULL)
    {
      args[i++] = ret_strtok;
      ret_strtok = strtok(NULL," ");
    }

    //Search for a built in command
    if (!strcmp(args[0],"exit"))
    {
      printf("Bye bye\n");
      return EXIT_SUCCESS;
    }
    else if (!strcmp(args[0],"cd"))
      printf("chdir\n");
   
   
    //If no built-it command is found, then ... let's look for the 
    //command 
    else{


      //We have a command to execute
      switch(pid = fork())
      {
        case -1 : perror("fork");break;

        case 0 : 
                  execvp(args[0],args);
                  break;
        default : wait(0);break;
      }

      free(command);
    }
      break;
    }


    return EXIT_SUCCESS;




  }
