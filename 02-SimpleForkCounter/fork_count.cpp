#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "counter.h"

using namespace std;

void Child()
{
  cout<<"Hello from child!"<<endl;
  Counter chc(10);
  while(chc.get()) {
     cout<<"Child: "<<chc.get()<<endl;
     chc.dec();
     cout.flush();
     sleep(1);
  }
}

void Parent()
{
  cout<<"Hello from parent!"<<endl;
  Counter pc(10);
  while(pc.get()) {
    cout<<"Parent: "<<pc.get()<<endl;
    pc.dec();
    cout.flush();
    sleep(1);
   }
}

int main()
{
   pid_t child;

   child=fork();
   switch(child)
   {
      case -1:
         cout<<"Fork error!"<<endl;
	 exit(1);
      case 0:
         Child();
	 break;
      default:
         Parent();
   }
   return 0;
}
