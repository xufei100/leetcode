#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 0 ) {
       return 0;
    }
    int validLen = 1;
    int prev = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > prev) {
            if (i != validLen) {
               nums[validLen] = nums[i];
            }
            validLen++;
            prev = nums[i];
        }
    }
    return validLen;
}

void test(int* nums, int len){
   printf("test result len %d  \n", len);
   for(int i = 0; i < len; i++)
   { 
       printf(" %d ", nums[i]);
   }
   printf("\n");
}

int main()
{
   int a[3] = {1,1,2};
   int b[10] = {0,0,1,1,1,2,2,3,3,4};
   int alen = removeDuplicates(a, 3);
   test(a, alen);
   int blen = removeDuplicates(b, 10);
   test(b, blen);  
   int c[] = {};
   removeDuplicates(c, 0);
}

