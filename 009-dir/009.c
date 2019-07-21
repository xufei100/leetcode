#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool isPalindrome(int x)
{
 
  if ( x < 0 || (x%10 == 0 && x !=0))
     return false;
  int reverseNum = 0;
  while ( reverseNum < x){
      reverseNum = reverseNum * 10 + x % 10;
      x = x /10;
  }
  printf("x %d reverseNum %d \n", x, reverseNum);
 return  (x == reverseNum || (reverseNum/10) == x);

}


bool isPalindromeT(int x)
{
   if (x < 0 )
      return false;
   if (x < 10 )
      return true;

   // 总长度
   int len = 0;
   int y = x;
   while (y !=0 ) {
     y = y/10; 
     len++;
   }
   printf("len %d\n", len); 
   // 中间长度
   int middle = len / 2;  
   
   int leftV = 0;
   int leftI = 0;
   int leftT = 0;
   int lcopy = x;
   while (leftI < middle)
   {
      int bottom = pow(10, (len - 1 - leftI));
      
      leftT = lcopy / bottom;
      lcopy = lcopy % bottom;
      leftI++;
      //printf("leftT %d leftI %d lcopy %d", leftT, leftI, lcopy);
      leftV = leftV * 10 + leftT;
   }   
   printf("leftV %d \n", leftV);


   int rightV = 0;
   int rightI = 0;
   int rightT = 0;
   int rcopy = x;
   while ( rightI < middle)
   {
        rightT = rcopy % 10;
        rcopy = rcopy / 10;
        rightV  = rightV * 10 + rightT;
        rightI++;
   }
   printf("rightV %d \n", rightV);
   if (leftV == rightV )
     return true;
   return false;
}


int main()
{
   printf("0 is palindrome %d \n\n", isPalindrome(0)); 
   printf("100 is palindrome %d \n\n", isPalindrome(100)); 
   printf("123 is palindrome %d \n\n", isPalindrome(123)); 
   printf("-123 is palindrome %d\n\n", isPalindrome(-123)); 
   printf("1234444 is palindrome %d\n\n", isPalindrome(1234444)); 
   printf("123321 is palindrome %d\n\n", isPalindrome(123321)); 
   printf("1234321 is palindrome %d\n\n", isPalindrome(1234321)); 


}
