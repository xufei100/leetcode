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

int* twoSum1(int *nums, int numsSize, int target, int* returnSize)
{
   int* result = malloc(2 * sizeof(int));
   int min = nums[0], max = nums[0];
   for(int i = 1; i < numsSize; i++) {
      if (nums[i] > max ) {
         max = nums[i];
      }
      if (nums[i] < min) {
         min = nums[i];
      }      
   }
   printf("min %d,max %d \n",min,max);
   
   int *hash = calloc((max-min), sizeof(int));
   if (hash == NULL ) {
      printf("malloc memroy fail");
      return NULL;  
   }
 
   for (int j = 0; j < numsSize; j++) {
       int diff = target - nums[j];
     //  printf("diff %d, %d   ", diff, hash[diff]);
       if (hash[diff])
       {
         result[0] = j;
         result[1] = hash[diff];
         printf("rs %d, %d   ", result[0], result[1]);
         *returnSize = 2;
         return result;
       }
       hash[nums[j]] = j;
    }
    return NULL;
}


int main()
{
  int* nums = (int []){1, 3, 2, 7, 11, 15, 18, 19, 20};
  int* nums1 = (int []){1, 3, 2, 7, 11, 15, 18, 19, 20};
  int  *returnSize, *rs;
  int  *rs1;
  int i = 0;
  returnSize = &i;
  rs = twoSum(nums, ARRAY_SIZE, 9, returnSize);
  printf("%d %d \n", rs[0], rs[1]);
  rs1 = twoSum1(nums1, ARRAY_SIZE, 9, returnSize);
  printf("%d %d \n", rs1[0], rs1[1]);
  /*while (*result != 0) {
     printf("%d  ",*result);
     result++;
  }*/
} 
