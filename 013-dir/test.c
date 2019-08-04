#include <stdio.h>
#include <string.h>

int main()
{
   char  *s = "abc";
   printf("%s\n", s);
   char t[10] = "123444";
   s = t;
   printf("%s \n", s);

}
