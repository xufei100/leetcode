#include <stdio.h>

int removeElement(int* nums, int numsSize,int val) 
{
    if (numsSize <= 0)
       return numsSize;
    int count = 0;
    for(int i = 0; i < numsSize; i++) {
       if (nums[i] == val) {
             count++;
       } else {
         if (count > 0 ) {
             nums[i-count] = nums[i];
         }
       }
    }
    return numsSize-count; 
}


int main()
{
  int array[8] = {0,1,2,2,3,0,4,2};
  int value = 2;
  int len = removeElement(array, 8, value);
  printf("len %d \n", len);
  for(int i = 0; i < len; i++) {
     printf("value %d  ", array[i]);
 }
}
