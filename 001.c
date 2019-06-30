#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SIZE  5

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
   for (int i = 0; i < numsSize - 1; i++) {
       for(int j = i + 1; j < numsSize; j++) {
              if (nums[i] + nums[j] == target) {
                  returnSize[0] = i;
                  returnSize[1] = j;
                  return returnSize;
              }
        }
    }
    return NULL;
}


int main()
{
  int* nums = (int []){1, 3, 2, 7, 11, 15, 18, 19, 20};
  int* result = malloc(2 * sizeof(int));
  int* rs;
  rs = twoSum(nums, ARRAY_SIZE, 9, result);
  printf("%d %d \n", rs[0], rs[1]);
  printf("%d %d \n", result[0], result[1]);
  while (*result != 0) {
     printf("%d  ",*result);
     result++;
  }
} 
