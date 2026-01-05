/*--------------    Display Complete File Information    --------------*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char* argv[])
{
    struct stat sobj;
    int iRet = 0;

    iRet = stat(argv[1],&sobj);
    printf("File type: ");

           switch (sobj.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }

    printf("Size : %ld\n",sobj.st_size);
    printf("Inode : %ld\n",sobj.st_ino);
    printf("Permissions : %ld\n",sobj.st_mode);
    printf("Hard links : %ld\n",sobj.st_nlink);
    printf("Owner Uid: %ld\nGid : %ld\n",sobj.st_uid,sobj.st_gid);
    printf("File type : %ld\n",sobj.st_mode);
    printf("Last Access time : %s",ctime(&sobj.st_atime));
    printf("Modify time : %s\n",ctime(&sobj.st_mtime));

    return 0;


}
