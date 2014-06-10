#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>


int main()
{
   DIR *dirp;
   struct dirent *dentry;
   dirp = opendir("/home");
   while ((dentry =  readdir(dirp)) != NULL) {
      printf("Name : %s ", dentry->d_name);
   }
   return 0;
}


