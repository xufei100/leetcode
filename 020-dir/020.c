#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.c"

bool isValid(char *s)
{
    for(; *s != '\0'; s++ ) {
       	if (strchr("([{", *s) != NULL) {
           // printf("put value is %c \n", *s);
            put(*s);
        }
        if ( strchr( ")]}", *s) != NULL) {
           char last = pop();
           //printf("pop value is  %c  \n", last);
          // printf("rs %d \n", *s == ')');
          // printf("rs1 %d \n", last == '(');
           if ( ( *s == ')' && last == '(' ) ||
                ( *s == ']' && last == '[' ) ||
                ( *s == '}' && last == '{' )
           ) {
              //   printf("enter here \n");
                  //return true;
           } else {
             reset();
             return false;
           }
        }
    }
    if (isEmpty()){
       return true;
    }else {
       reset();
    }
    return false;
}


int main()
{
   char *tts[10] = {"()", "()[]{}","{[([])]}","","(","()[]{", "{[([])","(]","([)]","{[]}"};
   int i = 0;
   bool rs = false;
   for(i = 0; i < 10; i++)
   {
       rs = isValid(tts[i]);
       printf("%s valid is: %d\n", tts[i], rs);
   }
}


