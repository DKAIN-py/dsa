#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node* node;

void node_at_end(node head){
    node temp = head ;
    node new_node = (node)malloc(sizeof(struct Node));
    if(new_node==NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter the data to be stored: ");
    scanf("%d", &new_node->data);
    while(temp->next!=NULL){
        temp = temp->next;
    }
    new_node->prev = temp;
    temp->next = new_node;
    new_node->next = NULL;
}

void traversal(node head){
    node temp = head;
    int i = 0, j = 0;
    printf("Straight traversal:\n");
    while(temp->next!=NULL){
        printf("\n(%d) Data: %d\n", i+1, temp->data);
        temp = temp->next;
        i++;
    }
    printf("\n(%d) Data: %d\n", i+1, temp->data);
    printf("\nReverse traversal:\n");
    while(temp!=NULL){
        printf("\n(%d) Data: %d\n", j+1, temp->data);
        temp = temp->prev;
        j++;
    }
}

void printval(node head){
    node temp = head;
    int i = 0;
    while(temp!=NULL){
        printf("\n(%d) Data: %d", i+1, temp->data);
        temp = temp->next;
        i++;
    }
}

void memoryfree(node head){
    node temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\nMemory freed!\n");
}

int main(){
    char choice;
    node head = (node)malloc(sizeof(struct Node));
    if(head==NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    head->prev=NULL;
    node_at_end(head);
    node_at_end(head);
    node_at_end(head);

    printval(head);
    printf("\nDo you want to add new node and then do full traversal?[y/n]: ");
    scanf(" %c", &choice);

    if(choice=='y' || choice=='Y'){
        node_at_end(head);
        traversal(head);
    }
    else if(choice=='n' || choice=='N'){
        traversal(head);
    }
    memoryfree(head);
    head=NULL;
    return 0;
}