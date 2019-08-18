#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printListValue(struct ListNode* p);

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode *l2pre = NULL;
    struct ListNode *first = l2; 
    for(; l1 != NULL; l1 = l1->next) {
        for (; l2 != NULL; l2 = l2->next) {
            if (l2->val > l1->val) {
               printf("l2 val %d, l1 val %d \n", l2->val, l1->val);
               struct ListNode *newNode = malloc(sizeof(struct ListNode));
               newNode->val = l1->val;
               newNode->next = l2;
               if (l2pre == NULL) {
                  first = newNode;
               }
               if (l2pre != NULL) {
                  l2pre->next = newNode;
               }
               l2pre = newNode;
               printf("process---\n ");
               printListValue(first);
               printf("process---end\n");
               break;    
            } else {
                 l2pre = l2;
            }  
        }
	if (l2 == NULL ) {
            struct ListNode *newNode = malloc(sizeof(struct ListNode));
            newNode->val = l1->val;
            newNode->next = l1->next;
            l2pre->next = newNode; 
            break;
        }        
    }  
    return first; 
}


struct ListNode* addToList(struct ListNode *list, int n) {
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    (*newNode).val = n;
    newNode->next = list;    
    return newNode;
}

struct ListNode* convertArrayToList(int *intArray, int arraySize) {
     struct ListNode *first = NULL;
     for (int i = arraySize-1; i >= 0; i--)
     {
         first = addToList(first, intArray[i]);
     }
     return first;
}

void printListValue(struct ListNode *first){
    printf("list value:");
    struct ListNode *p;
    for(p = first; p != NULL; p = p->next) {
      printf(" %d ", p->val);
    }
    printf("\n");
}


int main(){
    int a[3] = {5,6,7};
    struct ListNode *first = convertArrayToList(a, 3);
    printListValue(first); 
    
    int b[3] = {5,6,7};
    struct ListNode *second = convertArrayToList(b, 3);
    printListValue(second); 
     
    struct ListNode *merge = mergeTwoLists(first, second);
    printListValue(merge);

}
