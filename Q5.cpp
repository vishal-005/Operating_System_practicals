#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[]) {
    
    int fd1 , fd2;
    fd1 = open(argv[1] , O_RDONLY);
    fd2 = open(argv[2] , O_WRONLY|O_CREAT , 0777);
    int count_fd1 , count_fd2;
    char buffer[100];
    
    if(argc!=3)
    {
        cout<<"Error"<<endl;
        exit(100);
    }
    
    if(fd1<0)
    {
        cout<<"!!!!Error in opening file "<<endl;
    }
    
    else if(fd2<0)
    {
        cout<<"!!!Error in creating file "<<endl;
    }
    
    else
    
    while(count_fd1 = read(fd1,buffer,sizeof(buffer)))
    {
            count_fd2 = write(fd2,buffer,count_fd1);
    
            if(count_fd1!=count_fd2)
            {
                cout<<"!!!Error"<<endl;
            }
    }
    
    close(fd1);
    close(fd2);
 
}