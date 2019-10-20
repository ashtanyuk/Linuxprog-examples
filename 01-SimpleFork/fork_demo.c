#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
   pid_t child;

   child=fork();
   switch(child)
   {
      case -1:
         perror("Error!");
	 break;
      case 0:
         printf("Hello from child!\n");
	 break;
      default:
         printf("Hello from parent!\n");
   }
   return 0;
}
