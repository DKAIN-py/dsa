#include<stdio.h>
#include<stdlib.h>


typedef struct Node* node;

struct Node{
    int data;
    node left;
    node right;
};

node insert(node root, int data){
    if(root==NULL){
        node newnode = (node)malloc(sizeof(struct Node));
        newnode->left = newnode->right = NULL;
        newnode->data = data;
        return newnode;
    }

    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorder(node root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d, ", root->data);
    inorder(root->right);
}

int main(){
    node root = NULL;
    char choice;
    int data;
    do{
        printf("Enter the data of the new node: ");
        scanf("%d", &data);
        root = insert(root, data);
        printf("\nDo you want to continue [y/n]: ");
        scanf(" %c", &choice);
    }while(choice=='y' || choice=='Y');

    inorder(root);
    return 0;
}