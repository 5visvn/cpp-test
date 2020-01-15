#include <apue.h>


void pr_stdio(const char*, FILE*);
int is_unbuffered(FILE *);
int is_linebuffered(FILE*);
int buffer_size(FILE* );


int main(void)
{
   FILE * fp;
   fputs("enter any character\n", stdout);

   if (getchar() == EOF)
      err_sys("getchar error");
}
