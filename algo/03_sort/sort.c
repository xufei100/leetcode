#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int *nums, int numsSize){
    int i = 0;
    int j = 0;
    bool flag = false;
    for (int i = 0; i < numsSize; i++) {
        flag = false;
        for (int j = 0; j < numsSize - 1 - i; j++) {
            flag = false;
            if (nums[j] > nums[j+1]) {
               int t = nums[j+1];
               nums[j+1] =nums[j];
               nums[j] = t;
               flag = true;
            }
        }
            if (!flag) {
               break;
            }
    }
}


void insertionSort(int *nums, int numsSize)
{
  for (int i = 0; i < numsSize-1; i++) {
      int value = nums[i+1];
      int j = 0;
      bool exist = false;
      for(j = i ; j >= 0; j--)
      {
         if (nums[j] > value)
         {
            nums[j+1] = nums[j];
         } else {
             break;
         }
      }
      nums[j+1] = value;
  } 
}

void merge(int *nums,int start,int middle,int end) {
    int len = end - start + 1;
    int temp[len];
    int c = 0;
    int i = start;
    int j = middle+1;
    while( i <= middle && j <= end )
    {
       if (nums[i] < nums[j] ) {
            temp[c] = nums[i];
            i++;
         } else {
           temp[c] = nums[j];
           j++;
         } 
         c++;   
    }
    if (i == middle + 1) { // a is full
      for(; j <= end; j++) {
        temp[c] = nums[j];
        c++;
      }
    } else {
      for(; i <= middle; i++) {
         temp[c] = nums[i];
         c++;
       }
    }
    printf("sort start %d , middle %d ,end %d\n", start, middle, end);
    j = 0; 
    for(int i = start; i <= end; i++) {
       nums[i] = temp[j++];
       printf("%d ", nums[i]);
    }
    printf("\n");
}   

void mergeSort(int *nums, int start, int end)
{
    printf("start %d , end %d \n", start ,end );    
    if (start >= end)
    {
       return;
    }
    int middle = (end+start)/2;
    mergeSort(nums, start, middle);
    mergeSort(nums, middle+1, end);
    merge(nums, start, middle, end);
}

int findQ(int *nums,int start, int end)
{
    int p = nums[end];
    int minP = start;    
    for(int j = start; j < end; j++){
       if (nums[j] < p) {
           int t = nums[minP];
           nums[minP] = nums[j];
           nums[j] = t;
           minP++;
       }
   }
   int t = nums[minP];
   nums[minP] = p;
   nums[end] = t;
   printf("start %d ,end %d minPointer %d \n",start, end ,minP);
   for(int t = start; t <=end; t++) {
      printf("%d ",nums[t]);
   }
   printf("\n");
   return minP;
}

void quickSort(int *nums,int start, int end)
{
   if (start >= end) {
       return ;
   }
   int q = findQ(nums, start, end);
   quickSort(nums, start, q-1);
   quickSort(nums, q+1, end);
}

/**
*  寻找数组中第k大的元素，返回
*/
int lookTheKNumber(int *nums,int size, int k)
{
    if (k>size)
       return 0;
    int start = 0; 
    int end = size-1;
    int q = findQ(nums, start, end);
    while (q != k){
        if (q>k) {
           end = q-1;
           q = findQ(nums, start, end);
       }else {
           start = q+1;
           q = findQ(nums, start, end); 
       }
   }
   return nums[q];
}



int main()
{
    int nums[] = {4,5,6,3,2,1};
    int numsSize = 6;
    //bubbleSort(nums, numsSize);
    //insertionSort(nums, numsSize);
   // mergeSort(nums,0, numsSize-1);
    quickSort(nums,0, numsSize-1);
    printf("Sort result \n");
    for(int i = 0; i < numsSize; i++) {
      printf(" %d ", nums[i]);
    }
    printf("\n\n\n");
    int num1[] = {4,5,6,3,2,1};
    int t = lookTheKNumber(num1,6,3);
    printf("the 3 bigget number is %d\n", t);
}
