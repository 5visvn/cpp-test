#include "apue.3e/include/apue.h"
#include <dirent.h>

int main(int argc, char* argv[])
{
   DIR* dp;
   struct dirent* dirp;

   if (argc != 2)
   {
      printf("usage: ls directory_name\n");
      return 1;
   }

   if ((dp = opendir(argv[1])) == nullptr)
   {
      printf("can't open %s\n", argv[1]);
      return 1;
   }
   while ((dirp = readdir(dp)) != nullptr)
      printf("%s\n", dirp->d_name);

   closedir(dp);
   return 0;
}
