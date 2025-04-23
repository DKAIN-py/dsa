#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* node;

void new_node(node* head){
    node new_node = (node)malloc(sizeof(struct Node));
    
    if(new_node==NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the data to be stored:  ");
    scanf("%d", &new_node->data);
    if(*head == NULL){
        *head = new_node;
        new_node->next = *head;
    }
    else{
        node ptr = *head;
        do{
        ptr = ptr->next;
        }while(ptr->next!= *head);
        ptr->next = new_node;
        new_node->next = *head;
    }
}

void del_node(node* head_ref, int pos){
    if (*head_ref == NULL) {
        printf("List is empty!\n");
        return;
    }

    node head = *head_ref;
    node temp = head;
    node prev = NULL;
    int i = 0;

    // Handle deletion of the head node
    if (pos == 0) {
        while (temp->next != head) // Find the last node
            temp = temp->next;

        if (temp == head) { // Single node case
            free(head);
            *head_ref = NULL;
        } else {
            temp->next = head->next;
            free(head);
            *head_ref = temp->next;
        }
        return;
    }

    // Traverse the list to find the node at position `pos`
    while (i < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    // If position is invalid
    if (i < pos || temp == head) {
        printf("Position doesn't exist!\n");
        return;
    }

    // Update links and free memory
    prev->next = temp->next;
    free(temp);
}

void printval(node head){

    if(head==NULL){
        printf("List is empty!\n");
        exit(1);
    }

    node ptr = head;
    int i = 0;
    do{
        printf("\n(%d) Data: %d\n", i+1, ptr->data);
        ptr = ptr->next;
        i++;
    }while(ptr!=head);
}

void memoryfree(node head){
    node temp;
    node ptr = head;
    if(head==NULL){
        printf("List is empty!\n");
        exit(1);
    }
    do{
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }while(ptr != head);
    printf("Memory freed!!\n");
}

int main(){
    char choice;
    
    node head = (node)malloc(sizeof(struct Node));
    if(head==NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    head = NULL;
    new_node(&head);
    new_node(&head);
    new_node(&head);
    new_node(&head);
    printval(head);
    
    printf("What do you want to do?");
    printf("i for new node insertion\n");
    printf("d for deletion of node: ");
    scanf(" %c", &choice);

    if(choice == 'i' || choice=='I'){
        new_node(&head);
    }

    else if(choice=='d' || choice=='D'){
        int pos;
        printf("Enter the S.NO of node to be deleted: ");
        scanf("%d", &pos);
        del_node(&head, pos);
    }

    else{printf("Opreations completed!\n");}

    printval(head);
    memoryfree(head);
    head = NULL;
    return 0;
}