#include <errno.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_ip(unsigned int *ip_addr, const char *dns)
{
   struct hostent *hent = NULL;

   if (!dns || !(hent = gethostbyname(dns))) return -EINVAL;
   //TODO: support IPV6
   memcpy(ip_addr, hent->h_addr, 4);
   return 0;
}


int main()
{
  int rc = 0;
   unsigned int ip_addr;
   if(get_ip(&ip_addr, "localhost") != 0) {
      fprintf(stderr, "Unable to convert IP address "
            " to format used in RPC calls");
   } else {
      printf("IP address %d\n", ip_addr);
   }
   return 0;
}

 
