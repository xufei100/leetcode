#include <stdbool.h>
#include "stack.h"

#define ARRAY_SIZE 100

char charArray[ARRAY_SIZE];

int current = 0;

initStack()
{
    //charArray = (char *)malloc(ARRAY_SIZE * sizeof(char));
}

bool put(char c) {
 if (isFull())
 {
   //char * new = (char *)malloc(ARRAY_SIZE
   return false;
 }
 charArray[current] = c;
 current++;
// printf("stack put v is %c ,current is %d, cuurent v %c \n", c, current, charArray[current-1]);
 return true;
}

char pop() {
   if (isEmpty())
   {
      return ' ';
   }
   printf("stack pop value is %c ,current %d \n", charArray[current-1], current);
   return charArray[--current];
}

bool isEmpty() {
  if (current == 0)
     return true;
  return false;
}

bool isFull() {
    if (current >= ARRAY_SIZE) 
        return true;
    return false;
}

void reset()
{
  while(!isEmpty())
  {
     pop();
  }
}

