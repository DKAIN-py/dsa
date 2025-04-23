#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node* node;

struct Node{
    int data;
    node left;
    node right;
};

static int index = -1;
node buildtree(int preorder[]){
    index++;
    if(preorder[index]==-1){
        return NULL;
    }

    node root = (node)malloc(sizeof(struct Node));
    root->data = preorder[index];

    root->left = buildtree(preorder);
    root->right = buildtree(preorder);

    return root;
}

static int count = -1;
void inoder(node root, int sorrtedarr[]){
    if(root==NULL){
        return;
    }
    
    
    inoder(root->left, sorrtedarr);
    sorrtedarr[count] = root->data;
    count++;
    printf("%d ", root->data);
    inoder(root->right, sorrtedarr);

    
}

bool isSorted(int sortedarray[]){
    for(int i = 0; i<7; i++){
        printf("%d\n", sortedarray);
    }
    for(int i = 0; i<6; i++){
        if(sortedarray[i]>sortedarray[i+1]){
            printf("\nit aint true nigga\n");
            return false;
        }
    }
    printf("\nit is true nigga\n");
    return true;
}

int main(){
    int preorder[] = {4, 2, 1, -1, -1, 3, -1, -1, 6, 5, -1, -1, 7, -1, -1};
    int sortedarr[7];
    node root = buildtree(preorder);

    inoder(root, sortedarr);

    if(isSorted(sortedarr)==true){
        printf("\nThis is a Binary Search tree.\n");
    }

    else{
        printf("\nThis is not a Binary Search Tree.\n");
    }
    return 0;
}