#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
   int low = 0;
   int high = numsSize - 1;
   int first = -1;
   int second = -1;
   while (low <= high) {
       int mid = low + (high-low)/2;
       if (nums[mid] > target) {
           high = mid - 1;
       } else if (nums[mid] < target) {
           low = mid + 1;
       } else {
           int tt = mid;
           int hh = mid;
           while(tt != 0 && nums[tt-1] == target) {
               tt--;
           }
           first = tt;
           printf("first is %d\n", tt);
           while(hh != numsSize-1 &&  nums[hh+1] == target) {
              hh++;
           }
           printf("last is %d\n", hh);
           second = hh;
           break;
       }
   }
   int *rs = (int*)malloc(sizeof(int) * 2);
   rs[0] = first;
   rs[1] = second;
   *returnSize = 2;
   return rs;
}

int main()
{
    int nums[] = {5,7,7,8,8,8};
    int *returnSize;
    int i = 0;
    returnSize = &i;
    int *rs = searchRange(nums, 6, 5, returnSize);
     for(int i = 0; i < *returnSize; i++) {
         printf("%d  ",rs[i]);
     } 

}
