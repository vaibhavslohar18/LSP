/*--------------    Open File    --------------*/

#include<stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd ;

    fd = open(argv[1],O_RDONLY);

    if(fd != -1)
    {
        printf("File opened successfully!\nFile Descriptor :%d\n",fd);
    }
    else
    {
        perror("Unable to open file");
        return 1;
    }

    return 0;
}