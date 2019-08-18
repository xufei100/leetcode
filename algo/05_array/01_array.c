/**
  动态扩容数组
**/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 100

int size = 2;
int current = 0;
int *initP;
int *newArray;


void init()
{
   initP = malloc(size*2*sizeof(int));
}

bool  put(int i)
{
    if (current >= size) {
       printf("relocated....\n");
       initP = realloc(initP, size*2*sizeof(int));
       size = size * 2;
       /*
       newArray = malloc(size*2*sizeof(int));
       for (int i = 0; i < current; i++) {
           newArray[i] = initP[i]; 
           printf("copy i %d\n", initP[i]); 
       }
       size = size * 2;
       initP = newArray;
       */
     }
     initP[current] = i;
     current++;
     return true;
}

int  get(index)
{
  return initP[index];
}

int main()
{
  init();
  for (int  i = 0; i < SIZE; i++) {
      put(i);
  }
  for (int i = 0; i < SIZE; i++ ) {
      printf("index %d i value: %d \n",i,  get(i));
   }
}
