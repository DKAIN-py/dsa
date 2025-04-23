#include<stdio.h>
#include<stdlib.h>

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

// Simillar to inorder, we first visit left subtree, then right subtree and then root
// left subtree --> right subtree --> root
void postorder(node root){
    if(root==NULL){return;}

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


int main(){
    int preorder[] = {1,2,-1,3,-1,-1,4,-1,5,-1,6,-1,7,-1,-1};

    node root = buildtree(preorder);
    
    postorder(root);
    return 0;
}