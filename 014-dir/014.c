#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void  findCommonPrefix(char *s1, char *s2, char *totalRs)
{
   int len = strlen(s1);
   if (len == 0 ) {
       strcpy(totalRs , "");
       return ;
   }
   char result[len + 1];
   int count = 0;
   for( ;*s1 != '\0' && *s2 != '\0' && *s1 == *s2; s1++,s2++)
   {
        result[count] = *s1;
        count++;
   }
   if (count > 0)
   {
      result[count] = '\0';
      printf("count %d, rs %s \n", count, result);  
      strcpy(totalRs, result);
      printf("count %d, totalrs %s \n", count, totalRs);  
      return ;
   }
   strcpy(totalRs , "");
}

char * longestCommonPrefix(char ** strs,int strsSize)
{
    if (strsSize == 0)
        return "";

    int i = 0;
    char *rs = malloc(strlen(strs[0]) + 1);
    char *totalRs = malloc(strlen(strs[0]) + 1);
    strcpy(totalRs, strs[0]);
    for( i = 0; i+1 < strsSize; i++)
    {
        strcpy(rs, totalRs);
        findCommonPrefix(rs, strs[i+1], totalRs);
        printf("outside totalRs %s", totalRs);
        if (strlen(totalRs) == 0) {
           return "";
        }
    }
    return totalRs;
}

int main()
{
  char *c[] = {"dddd","ddfefeee", "ddffefefe", "eefefe", "effefeefe"};
  char *d = longestCommonPrefix(c, 3);
  printf("result %s\n", d);
}
