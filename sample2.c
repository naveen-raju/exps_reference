#include <stdio.h>
#include <fcntl.h>
#include <ibrtypes.h>

#define POID_FMT "%Lx%x"
#define POID2STR(_bufferstr, _poid)          \
   sprintf(_bufferstr,                                    \
         POID_FMT, _poid.hi64, _poid.lo32)                 \


int main(int argc, char *argv[]) 
{
   char poidstr[40];
   int fd, rc = 1;
   INODE_ID id;
   fd = open(argv[1], O_RDONLY);
   if (fd < 0) {
      printf("Error Opening file\n");
      return 1;
   }

   while(rc > 0) {
         rc = read(fd, (unsigned char *) &id, sizeof(INODE_ID));
         POID2STR(poidstr, id.ibr_poid);
         printf("POID: %s\n", poidstr);
   }
   fflush(stdout);
   return 0;
}
