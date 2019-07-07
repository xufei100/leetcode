#include <stdio.h>

void arrayT()
{
    int a[4] = {1,3,5,7};
    printf("len %d\n",sizeof(a)/sizeof(int));
    printf("a0 %d\n", *a);
    printf("a1 %d\n", *(a+1));
    printf("a1 %d\n", a[1]);
 // error
 //   printf("next %d\n", *a++);
    printf("a1 %d\n", a[1]);
  // error 
  //   int b[4] = {1,3,5,4};
  //  a = b;
}

void pointT(int a[])
{
    printf("len %d\n",sizeof(a)/sizeof(int));
    printf("a0 %d\n", *a);
    printf("a1 %d\n", *(a+1));
    printf("a1 %d\n", a[1]);
    printf("a++ %d\n", *a++);
    printf("a1 %d\n", a[1]);
    int b[4] = {10,30,50,40};
    a = b;
    printf(" new a0%d\n", a[0]);
}

void  arrayTest(int t[])
{
  printf("%d", sizeof(t));
}

int main()
{
  arrayT();
  printf("----------------\n");
  int a[4] = {1,3,5,7};
  pointT(a);
  printf("----------------\n");
  pointT(a);
  return 1; 
} 
