#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node* node;

struct Node{
    int data;
    node left;
    node right;
};

node insert(node root, int data){
    if(root==NULL){
        node newnode = (node)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    if(data > root->data){
        root->right = insert(root->right, data);
    }
    else if(data < root->data){
        root->left = insert(root->left, data);
    }

    return root;
}

void search(node root, int elem){
    if(root==NULL){
        printf("Element not found in Tree.\n");
        return;
    }

    if(elem > root->data){
        search(root->right, elem);
    }
    else if(elem < root->data){
        search(root->left, elem);
    }

    else{
        printf("Given element found in the tree: %d\n", root->data);
        return;
    }
}

int main(){
    node root = NULL;
    char choice;
    int data;
    int numcho;
    while(true){
        printf("\n--- MENU ---\n");
        printf("1. Create new node\n2. Search for an element\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &numcho);
        switch(numcho){
            case 1:
                do{
                    printf("Enter the data of the new node: ");
                    scanf("%d", &data);
                    root = insert(root, data);
                    printf("\nDo you want to continue [y/n]: ");
                    scanf(" %c", &choice);
                }while(choice=='y' || choice=='Y');
                break;
            case 2:
                do{
                    int ele;
                    printf("Enter the element to be searched for: ");
                    scanf("%d", &ele);
                    search(root, ele);
                    printf("\nDo you want to continue [y/n]: ");
                    scanf(" %c", &choice);
                }while(choice=='y' || choice=='Y');
                break;
            default:
                break;
        }
        if(numcho>2){break;}
    }
    
    return 0;
}