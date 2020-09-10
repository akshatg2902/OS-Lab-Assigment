//Akshat Gupta(181112052)
//A-6  Q-2(Demonstrate the race condition using fork()systemcall.)

#include<unistd.h>
#include<stdlib.h>
int main()
{
    int pid,j;
    pid=fork();
    if(pid==0)
    {
        for(j=1;j<=10;j++)
         printf(1\nChild here);
        exit(0);
    }
    else
    {
        for(j=1;j<=10;j++)
         printf(2\nParent here);

    }
   exit(0);
}
