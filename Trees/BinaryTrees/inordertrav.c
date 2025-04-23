#include<stdio.h>
#include<stdlib.h>

typedef struct Node* node;

struct Node{
    int data;
    node left;
    node right;
};


static int index = -1;
node buildtree(int arr[]){
    index++;
    if(arr[index]==-1){
        return NULL;
    }
    node root = (node)malloc(sizeof(struct Node));
    root->data = arr[index];

    root->left = buildtree(arr);
    root->right = buildtree(arr);

    return root;
}

// in Inoder traversal, we first visit left subtree of root even before 
// visiting root, then we visit root and then right subtree
// left subtree --> root --> right subtree
void inoder(node root){
    if(root==NULL){
        return;
    }

    inoder(root->left);
    printf("%d ", root->data);
    inoder(root->right);
} 

int main(){
    int preorder[] = {1,2,-1,3,-1,-1,4,-1,5,-1,6,-1,7,-1,-1};

    node root = buildtree(preorder);

    inoder(root);
    return 0;
}