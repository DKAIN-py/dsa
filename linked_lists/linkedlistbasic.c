#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printval(struct Node * ptr){
    while(ptr!=NULL){
        printf("\nData : %d\n", ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    
    struct Node * head; 
    struct Node * first;
    struct Node * second;
    struct Node * last;
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    last = (struct Node*)malloc(sizeof(struct Node));

    head->data = 0;
    head->next = first;

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = last;

    last->data = 3;
    last->next = NULL;

    printval(head);
    free(head);
    free(first);
    free(second);
    free(last);

    return 0;
}