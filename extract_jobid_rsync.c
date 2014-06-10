#include <stdio.h>
#include <string.h>

#define JOBID_STR "<jobid="


int main(int argc, char *argv[])
{
   char *jobidstr = NULL;
   int count = 0;
   char *logfile_format, *tmpstr;
   logfile_format = strdup("%s %d %r %t <jobid=1221> asdasd");
   
   if (logfile_format && 
         strstr(logfile_format, JOBID_STR) &&
         !jobidstr) {
      tmpstr = strstr(logfile_format, JOBID_STR);
      while (tmpstr && *tmpstr != '\0' && *tmpstr != '>') tmpstr++, count++;
      if (*tmpstr != '\0') (*tmpstr) = '\0';
      tmpstr = tmpstr - count;
      printf("Extracted job id string %s from string %s" , tmpstr, logfile_format);
   }
   free(logfile_format);
   return 0;
}
