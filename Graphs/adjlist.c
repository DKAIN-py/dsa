#include<stdio.h>
#include<stdlib.h>

typedef struct Node* node;

struct Node {
    int vertex;
    node next;
};

node createnode(int vertex){
    node newnode = (node)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("Memeory allocation failed\n");
        return NULL;
    }

    newnode->vertex = vertex;
    newnode->next = NULL;
    return newnode;
}

void graph(node adjlist[], int vertices, char type){
    int src, dest;
    char choice;
    while(1){
        printf("Enter the source and destionation of vertices you want to link (source,destination): ");
        scanf(" %d,%d",&src,&dest);

        if(src==dest){
            printf("Self linkage is not allowed for this graph.\n"); // self linkage edge case
            continue;
        }

        if(src>=vertices || dest>=vertices || src<0 || dest<0){ // out of bound edge case
            printf("Invalid vertex.\n");
            continue;
        }

        node temp = adjlist[src];
        while(temp->next!=NULL){
            if(temp->vertex==dest){
                printf("Linkage already ready present...\n"); // linkage already present edge case
                break;
            }
            temp = temp->next;
        }
        if(type=='d' || type=='D'){
            temp->next = createnode(dest);
        }
        else if(type=='u' || type=='U'){
            temp->next = createnode(dest);
            node temp2 = adjlist[dest];
            while(temp2->next!=NULL){
                if(temp2->vertex==dest){
                    printf("Linkage already ready present...\n"); // linkage already present edge case
                    goto skip;
                }
                temp2 = temp2->next;
            }
            temp2->next = createnode(src);
        }
        skip:
        printf("Do you want to continue [y/n]: ");
        scanf(" %c", &choice);
        if(choice=='n' || choice=='N') break;
    }
    
}

void display(node adjlist[], int vertices){
    for(int i = 0; i<vertices; i++){
        node temp = adjlist[i]; // skip dummy head
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");

    }
}

int main(){
    int vertices;
    char type;
    printf("Enter the number of vertices you want: ");
    scanf("%d",&vertices);

    node adjlist[vertices];
    for (int i = 0; i < vertices; i++) {
        adjlist[i] = createnode(i);  // dummy head
    }

    printf("What kind of graph you want, directional or undirectional [d/u] : ");
    scanf(" %c", &type);
    graph(adjlist,vertices, type);

    display(adjlist,vertices);

    return 0;
}


// edge cases:- 
// out of bound linkage, vertices > no. of vertices || vertx < 0
// linkage already present 
// self linkage, source == destination