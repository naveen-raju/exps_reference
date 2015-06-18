#include <stdio.h>
#include <linux/limits.h>
#include <time.h>
#include <string.h>

#include <ftw.h>

struct stat sb;
int count = 0;
time_t dir_mtime;
double min_diff_time = 10.0;
char pathname[PATH_MAX];

static int get_latest_file(const char *name, struct stat *buf, 
      int tflag, struct FTW *ftwbuf)
{

   if (tflag == FTW_F) {
      if (difftime(dir_mtime, buf->st_mtime) < min_diff_time)
      {
         memcpy(&dir_mtime , &buf->st_mtime, sizeof(time_t));
         min_diff_time = difftime(dir_mtime, buf->st_mtime);
         count++;
         sprintf(pathname, "%s", name);
      }
   }
   return 0;
}

int main(int argc, char *argv[])
{
   int flags = 0;
   flags |= FTW_SKIP_SUBTREE;
   char dir_path[PATH_MAX];
   sprintf(dir_path, "%s", argv[1]);
   stat(dir_path, &sb);
   memcpy(&dir_mtime, &sb.st_mtime ,sizeof(time_t));
   while(nftw(dir_path, get_latest_file, 10, flags) > 0);
   printf("Latest file in the directory %s is %s , Total files:%d",dir_path, 
         pathname, count);
   return 0;
}
