#include<stdio.h>
#include<stdlib.h>

typedef struct Node* node;

struct Node{
    int data;
    node left;
    node right;
};

node inOredersucceser(node root){
    root = root->left;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

node delete(node root, int key){
    node isuc;
    if(root==NULL){
        return NULL;
    }
    
    if(root->left == NULL && root->right == NULL){
        free(root);
        return root;
    }

    // node to be deleted
    if(key > root->data){
        delete(root->right, key);
    }
    else if (key < root->data){
        delete(root->left,key);
    }
    else{
        isuc = inOredersucceser(root);
        root->data = isuc->data;
        root->right = delete(root->right, isuc->data);
    }
    return root;
}


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
    int data, val;

    do{
        printf("Enter the data of the new node: ");
        scanf("%d", &data);
        root = insert(root, data);
        printf("\nDo you want to continue [y/n]: ");
        scanf(" %c", &choice);
    }while(choice=='y' || choice=='Y');

    inorder(root);

    printf("Enter the value to be deleted: ");
    scanf("%d", &val);
    
    delete(root,val);
    printf("\n");
    inorder(root);
    
    return 0;
}