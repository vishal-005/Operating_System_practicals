    //Input A

#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <iostream>
using namespace std;


int main()
{
    cout<<"SAME PROGRAM SAME CODE : "<<endl;
    pid_t pid;
    pid=fork();

    
    if(pid<0)
    {    
        cout<<"Error , Child Not Created"<<endl;
        
    }
    
    else
    {
        system("ls");
    }
    
    
    return 0;
}


//Input B

#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <iostream>
using namespace std;



int main()
{
    cout<<"SAME PROGRAM D/F CODE : "<<endl;
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        system("ls");
    }
    else if(pid<0)
    {
        cout<<"Error , Child Not Created"<<endl;
    }

    else
    {
        system("ls -l");
    }
    
    
    return 0;
}


//Input C


#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <iostream>
#include<sys/wait.h>
using namespace std;

int main()
{
    
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        cout<<endl<<"This is a child process : "<<endl;
        cout<<"Working directory is :  "<<endl;
        execlp("pwd" , "pwd" , NULL);
        cout<<endl;
        
    }
    
    else
    {    
        wait(NULL);
        cout<<endl<<"Parent Process : "<<endl;
        cout<<"Files in working directory are : "<<endl;
        cout<<("ls" , "ls" , NULL);
        cout<<endl;
        
        
    }

    return 0;
}