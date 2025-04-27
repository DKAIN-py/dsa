#include<stdio.h>
#include<stdlib.h>

typedef struct Node* node;

struct Node {
    int data;
    node left;
    node right;
    int height;
};

int max(int num1, int num2){
    return num1>num2?num1:num2;
}


int getheight(node n){
    if(n==NULL) return 0;
    return n->height;
}

node createnode(node root, int key){
    node new_node = (node)malloc(sizeof(struct Node));
    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

node RRotate(node x){
    node y = x->left;
    node yRT = y->right; // Right subtree of y

    y->right = x;
    x->left = yRT;

    x->height = max(getheight(x->left),getheight(x->right)) + 1;
    y->height = max(getheight(y->left),getheight(y->right)) + 1;
    
    return y;
}   

node LRotate(node y){
    node x = y->right;
    node xLT = x->left; // Left subtree of x

    x->left = y;
    y->right = xLT;

    x->height = max(getheight(x->left),getheight(x->right)) + 1;
    y->height = max(getheight(y->left),getheight(y->right)) + 1;
    
    return x;
}

int getBF(node root){
    if(root==NULL)return 0;

    return getheight(root->left) - getheight(root->right);
}

node insert(node root, int key){
    if(root==NULL) return createnode(root,key);

    if(key>root->data)
        root->right = insert(root->right, key);
    else if(key<root->data)
        root->left = insert(root->left, key);
    else
        return root;

    root->height = max(getheight(root->left), getheight(root->right)) + 1;

    int BF = getBF(root);

    if(BF > 1 && key < root->left->data){
        return RRotate(root);               // LL rotation
    }

    else if(BF < -1 && key > root->right->data){
        return LRotate(root);               // RR rotation
    }

    else if(BF > 1 && key > root->left->data){
        root->left = LRotate(root->left);
        return RRotate(root);                // LR rotation  
    }

    else if( BF < -1 && key < root->right->data){
        root->right = RRotate(root->right);
        return LRotate(root);               // RL rotation
    }

    return root;
}

void inoder(node root){
    if(root==NULL){
        return;
    }

    inoder(root->left);
    printf("%d ", root->data);
    inoder(root->right);
}

int isAVL(node root){
    if(root == NULL)
        return 1; // NULL tree is AVL

    int lh = getheight(root->left);
    int rh = getheight(root->right);

    if(abs(lh - rh) <= 1 && isAVL(root->left) && isAVL(root->right))
        return 1;

    return 0;
}


int main(){
    node root = (node)malloc(sizeof(struct Node));

    root = insert(root, 23);
    root = insert(root, 87);
    root = insert(root, 45);
    root = insert(root, 66);
    root = insert(root, 12);
    root = insert(root, 99);
    root = insert(root, 34);
    root = insert(root, 78);
    root = insert(root, 55);
    root = insert(root, 61);

    printf("Inorder Traversal of AVL tree: ");
    inoder(root);

    if(isAVL(root))
    printf("\nTree is an AVL Tree!\n");
    else
    printf("\nTree is NOT an AVL Tree!\n");


    return 0;
}


