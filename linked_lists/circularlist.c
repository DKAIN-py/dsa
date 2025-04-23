#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node* node;

void printval(node head){
    node ptr = head;
    int i = 0;
    printf("\nS.NO are for refrence only.\n");
    do{
        printf("\n(%d) Data: %d\n", i+1, ptr->data);
        ptr = ptr->next;
        i++;
    }while(ptr!=head);
}

int main(){
    
    node head; 
    node first;
    node second;
    node last;
    head = (node)malloc(sizeof(struct Node));
    first = (node)malloc(sizeof(struct Node));
    second = (node)malloc(sizeof(struct Node));
    last = (node)malloc(sizeof(struct Node));

    head->data = 0;
    head->next = first;

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = last;

    last->data = 3;
    last->next = head;

    printval(head);
    free(head);
    free(first);
    free(second);
    free(last);

    return 0;
}