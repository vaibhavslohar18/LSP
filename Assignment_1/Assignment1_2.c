/*--------------    Open File in Given Mode    --------------*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd ;
    int Mode;
    

    if(strcmp(argv[2], "R") == 0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2], "W") == 0 )
    {
        Mode = O_WRONLY;
    }
    else if(strcmp(argv[2], "RW") == 0 )
    {
        Mode = O_RDWR;
    }
    else if(strcmp(argv[2], "A") == 0 )
    {
        Mode = O_APPEND;
    }
    else
    {
        printf("Invalid mode.\n");
    }

    fd = open(argv[1],Mode);

    if(fd != -1)
    {
        printf("File opened successfully!\nFile Descriptor :%d\n",fd);
        switch(Mode)
        {
            case 0:
                printf("File Mode :Read Only\n");
                break;
            case 1:
                printf("File Mode :Write Only\n");
                break;
            case 2:
                printf("File Mode :Read Write\n");
                break;
            case 02000:
                printf("File Mode :Append\n");
                break;
        }
    }
    else
    {
        perror("Unable to open file");
        return 1;
    }

    return 0;
}