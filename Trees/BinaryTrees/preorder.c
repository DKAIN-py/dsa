#include<stdio.h>
#include<stdlib.h>

typedef struct Node* node;

struct Node {
    int data;
    node left;
    node right; 
};

static int index = -1;

node BuildTree(int preorder[]){
    index++;
    if(preorder[index]==-1){
        return NULL;
    }

    node root = (node)malloc(sizeof(struct Node));
    root->data = preorder[index];

    root->left = BuildTree(preorder);
    root->right = BuildTree(preorder);

    return root;

}



int main(){
    int preorder[] = {1,2,-1,3,-1,-1,4,-1,5,-1,6,-1,7,-1,-1};

    node root = BuildTree(preorder);
    printf("%d", root->data);
    printf("%d", root->left->data);
    printf("%d", root->right->data);
    // printf("%d", root->left->left->data);
    printf("%d", root->right->right->data);

    return 0;
}