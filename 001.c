#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SIZE  5

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{  
   int* result = malloc(2 * sizeof(int));
   for (int i = 0; i < numsSize - 1; i++) {
       for(int j = i + 1; j < numsSize; j++) {
              if (nums[i] + nums[j] == target) {
                  result[0] = i;
                  result[1] = j;
                  *returnSize = 2;
                  return result;
              }
        }
    }
    return NULL;
}


int main()
{
  int* nums = (int []){1, 3, 2, 7, 11, 15, 18, 19, 20};
  int  *returnSize, *rs;
  int i = 0;
  returnSize = &i;
  rs = twoSum(nums, ARRAY_SIZE, 9, returnSize);
  printf("%d %d \n", rs[0], rs[1]);
  /*while (*result != 0) {
     printf("%d  ",*result);
     result++;
  }*/
} 
