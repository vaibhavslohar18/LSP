/*--------------    Read N Byte From File    --------------*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define SIZE 100

int main(int argc, char *argv[])
{
    int fd      = 0;
    int iret    = 0;
    int User_size    = atoi(argv[2]);
    char Buffer[SIZE];

    memset(Buffer,'\0',SIZE);

    fd = open(argv[1], O_RDONLY);
    
    if(fd < 0)
    {
        printf("Unable to open file\n");
        printf("Reason : %s\n",strerror(errno));
        return (-1);
    }

    printf("Containt from file\n");

    iret = read(fd,Buffer,User_size);

    printf("%d Bytes read from file.\n",iret);

    printf("Data from file : %s\n",Buffer);

    close(fd);

    return 0;
}