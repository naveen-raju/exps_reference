#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
   int fd;
   fd = open("dummy.data", O_CREAT|O_WRONLY);
   int offset = lseek(fd, 20000000000, SEEK_SET);
   if (offset < 0) {
      printf("Cannot create a 20 GB sparse file, offset %d, errno %d\n", offset, errno);
      exit(0);
   }
   write(fd, "simple_string", strlen("simple_string"));
   close(fd);
   return 0;
}



