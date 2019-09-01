#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle)
{
   if (strcmp(needle,"") == 0 ) {
      return 0;
   }
   if (strcmp(haystack,"") == 0) {
       return -1;
   }
  
   int index = 0;
   int j = 0;
   while(haystack[index] != '\0') {
           j = 0;
	   for(; needle[j] != '\0'; j++) {
	       if (needle[j] != haystack[index+j]){
		     break;
	       }
           } 
           if (needle[j] == '\0') {
              return index;
           }
           index++;
    }
    return -1;
}



int main()
{
    printf("ll in hello %d\n",strStr("hello", "ll"));
    printf("bba in aaaa %d\n",strStr("aaaa", "bba"));
    printf("empty in hello %d\n",strStr("hello", ""));
    printf("he  in hello %d\n",strStr("hello", "he"));
    printf("wo  in hello world %d\n",strStr("hello world", "wo"));
    printf("ld  in hello world %d\n",strStr("hello world", "ld"));
}
