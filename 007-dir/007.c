#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define INT_MAX 2147483647
#define INT_MIN -2147483648

int reverse(int x)
{
 int result = 0;
 int y ;
 while (x != 0) {
   y = x % 10;
   x = x / 10;
   if (result > INT_MAX/10 || (result == INT_MAX/10 && y > 7)) {
        return 0;
   }
   if (result < INT_MIN/10 || (result == INT_MIN/10 &&  y < -8)) {
      return 0;
   }
   result = result * 10 + y;
 }
 return result;
}


int main()
{
 int i = 123;
 int ri = reverse(i);
 printf("i %d ri %d \n", i, ri); 
 int j = -123;
 int rj = reverse(j);
 printf("j %d rj %d \n", j, rj); 
 
 int k = 2147483647;
 int rk = reverse(k);
 printf(" k %d rk %d \n", k ,rk);
 return 1;
}
