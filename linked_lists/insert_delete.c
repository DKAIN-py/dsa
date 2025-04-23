#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
};

typedef struct Node*  node;

// adding node at begging
void node_at_beg(node* head){
    node new_node;
    new_node = (node)malloc(sizeof(struct Node));
    if(new_node==NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the data you want to store: ");
    scanf("%d", &new_node->data);
    new_node->next = *head;
    *head = new_node;
}

// adding node at end
void node_at_end(node head){
    node new_node;
    node ptr = head;
    new_node = (node)malloc(sizeof(struct Node));
    if(new_node==NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the data you want to store: ");
    scanf("%d", &new_node->data);
    while(ptr->next!=NULL){
        ptr = ptr->next; 
    }
    ptr->next = new_node;
    new_node->next = NULL;
}


// adding node in between nodes
void node_in_between(node head, int len){
    node new_node;
    node temp = head;
    int i = 1, pos;
    new_node = (node)malloc(sizeof(struct Node));
    if(new_node==NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the S.NO of node after which you want to add new node: ");
    scanf("%d", &pos);
    if(pos<=0 || pos>=len){
        printf("Given positon is undefined. Are you trying to add new node at begging or end?\n");
        free(new_node);
        exit(1);

    }
    while(i < pos && temp != NULL){
        temp = temp->next;
        i++;
    }
    if(temp!=NULL){
        printf("Enter the data you want to store: ");
        scanf("%d", &new_node->data);
        new_node->next = temp->next;
        temp->next = new_node; 
    }
    else{
        printf("Entered S.NO either doesn't exists or is the last node..\n");
        free(new_node);
        exit(1);
    }

}

void del_node_beg(node* head){
    node temp = *head;
    *head = (*head)->next;
    free(temp);
}

void del_node_bet(node head, int len, int pos){
    node curr = head;
    node prev = NULL; 
    int i = 0;
    while(i < pos-1 && curr->next != NULL){
        prev = curr;
        curr = curr->next;
        i++;
    }
    if (curr != NULL && prev != NULL) {
        prev->next = curr->next; // Skip the node to be deleted
        free(curr);              // Free the node
    } 
    else {
        printf("Invalid position.\n");
    }
}

void del_node_end(node head){
    node temp = head;
    node prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    // If the list has more than one node
    if (prev != NULL) {
        prev->next = NULL; // Unlink the last node
    } else {
        head = NULL; // If the list has only one node, set head to NULL
    }

    free(temp); // Free the last node
}

// printing the linked list
void printval(node head){
    int i = 0;
    node ptr = head;
    while(ptr!=NULL){
        printf("\n(%d) Data : %d\n", i+1,ptr->data);
        ptr=ptr->next;
        i++;
    }
}


// to find length of the list
int linklen(node head){
    int i = 0;
    struct Node * ptr = head;
    while(ptr!=NULL){
        ptr=ptr->next;
        i++;
    }
    return i;
}


// to free the dynamicaly allocated memory
void memoryfree(node ptr){
    node temp;
    while(ptr!=NULL){
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

int main(){
    char choice;
    char inserchoice;
    char nodeno;
    node head = (node)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    head->data = 0;
    head->next = NULL;

    node_at_end(head); // Add node with data 1
    node_at_end(head); // Add node with data 2
    node_at_end(head); // Add node with data 3 
    
    printval(head);
    printf("What do you want to do?\n");
    printf("d for deleting node.\n");
    printf("i for inserting a node.\n");
    scanf(" %c", &choice);

    if(choice=='d'){
        printf("\nEnter the S.NO of node you want to delete: ");
        scanf("%d", &nodeno);

        if(nodeno==1){
            del_node_beg(&head);
        }
        else if (nodeno> 1 && nodeno<linklen(head)){
            del_node_bet(head, linklen(head), nodeno);
        }
        else if (nodeno==linklen(head)){
            del_node_end(head);
        }
        else{
            printf("Invalid input!.\n");
        }
    }

    else if (choice=='i'){
        printf("\nWhere do you want to add new node? starting, between, end (s/b/e): ");
        scanf(" %c", &inserchoice);
        switch (inserchoice){
            case 's':
                node_at_beg(&head);            
                break;
            case 'b':
                node_in_between(head, linklen(head));
                break;
            case 'e' :
                node_at_end(head);
                break;
            default:
                printf("\nNo more features available(for now at least!!)\n");
        }
    }
    else{
        printf("\nNo more features available(for now at least!!)\n");
        
    }
    printval(head);
    memoryfree(head);
    head = NULL;


    return 0;
}


