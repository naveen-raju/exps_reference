#include <stdio.h>
#include <unistd.>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char sparse_file[] = "sparse.dat"
char index_file[] = "index.dat"

typedef data {
   int offset;
   int pos;
} DATA;

int main(int argc, char *argv[])
{

   int i;
   int fd1, fd2;
   off_t offset, wret;
   DATA datum;

   fd1 = open(sparse_file, O_CREAT|O_RDWR);
   if (fd1 < 0) {
      printf("failed to open file %s, %d", sparse_file, errno);
      exit(1);
   }

   fd2 = open(index_file, O_CREAT|O_RDWR);
   if (fd1 < 0) {
      printf("failed to open file %s, %d", index_file, errno);
      exit(1);
   }   
   
   for (i = 0;i < n;i++) {
      offset = lrand48();
      offset = lseek(fd1, offset, SEEK_SET);
      wret = write(fd1, 




   }


}
