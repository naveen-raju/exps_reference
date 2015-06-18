#include <stdio.h>
#include <linux/limits.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   struct stat buf, sb;
   DIR *dirfd;
   struct dirent *dentry;
   char fname[PATH_MAX], cwdir[PATH_MAX];
   double min_diftime = 10.0;
   int rc;
   int count = 0;

   sprintf(cwdir, "%s", ".");
   //initialise fname to dummy value
   sprintf(fname, "%s", "dummy");
   
   getcwd(cwdir, PATH_MAX);
   rc = stat(argv[1], &sb);
   if (rc < 0) {
      printf("Unable to open the directory\n");
      return 1;
   }
   
   dirfd = opendir(argv[1]);
   if (!dirfd) {
      printf("Unable to open the directory\n");
      return 1;
   }

   chdir(argv[1]);

   while ((dentry = (struct dirent *)readdir(dirfd)) != NULL) {
      if (stat(dentry->d_name, &buf) < 0) {
         //ignore file stat failures
         continue;
      }
      
      if (!S_ISREG(buf.st_mode)) continue;

      if (difftime(sb.st_mtime, buf.st_mtime) < min_diftime) {
         sprintf(fname, "%s", dentry->d_name);
         min_diftime = difftime(sb.st_mtime, buf.st_mtime);
         count++;
      }
   }

   chdir(cwdir);
   printf("Current working  directory %s " , cwdir);
   printf("Newest file in the dir %s is %s \n", argv[1], fname);
   if (count == 0) return 0;
   return 0;
}
