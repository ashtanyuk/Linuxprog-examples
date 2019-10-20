#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "counter.h"

using namespace std;

void Child()
{
  cout<<"Hello from child!"<<endl;
  Counter chc(10);
  while(chc.get()) {
     cout<<"Child: "<<chc.get()<<endl;
     cout.flush();
     sleep(1);
     chc.dec();
  }
}

void Parent(pid_t child)
{

  cout<<"Hello from parent! "<<child<<endl;
  Counter pc(10);
  wait(&child); // we're waiting child's finish
  while(pc.get()) {
    cout<<"Parent: "<<pc.get()<<endl;
    cout.flush();
    sleep(1);
    pc.dec();
   }
}

int main()
{
   pid_t child;

   child=fork(); // child's pid
   switch(child)
   {
      case -1:
         cout<<"Fork error!"<<endl;
	       exit(1);
      case 0:
         Child();
	 break;
      default:
         Parent(child); 
   }
   return 0;
}
