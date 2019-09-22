#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
   int low = 0;
   int high = numsSize -1;
   
   while(low <=high) {
       int m = low + (high-low)/2;
       if (nums[m] > target) {
           high = m -1;
       } else if(nums[m] < target) {
          low = m + 1;
       } else {
         return m;
      }
    }
    return high+1;
}


int main()
{
    int tt[] = {1,3,5,6,9};
    int t = searchInsert(tt,5,5);
    int s = searchInsert(tt,5,4);
    int r = searchInsert(tt,5,0);
    int r1 = searchInsert(tt,5,2);
    printf("5 in t index is %d\n", t);
    printf("4 in t index is %d\n", s);
    printf("0 in t index is %d\n", r);
    printf("2 in t index is %d\n", r1);
}
