/*--------------    Check File Access Permission    --------------*/
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Mode = 0;

    Mode =  argv[2];
    fd = access(argv[1], Mode);

    if(fd == 0)
    {
        perror("The given file is accessible.\n");
    }
    else
    {
        perror("The given file is Not accessible.\n");
    }

    
}
