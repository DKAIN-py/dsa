#include<stdio.h>
#include<stdbool.h>
#define MAX 100

void graph(int adjMat[MAX][MAX], int vertices, char type){
    char choice;
    while(1){
        int src,dest;  
        printf("Enter the source and destionation of vertices you want to link (source,destination): ");
        if (scanf("%d,%d", &src, &dest) != 2) {
            printf("Invalid input format. Try again.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        if(src>=vertices || dest>=vertices || src<0 || dest<0){
            printf("Invalid vertex.\n");
            continue;
        }

        if(adjMat[src][dest]==1){
            printf("Vertices already linked.\n");
            continue;
        }
        if(type=='d' || type=='D'){             // directional graph
            adjMat[src][dest]=1;
        }
        else if(type=='u' || type=='U'){            // undirectional graph
            adjMat[src][dest]=1;
            adjMat[dest][src]=1;
        }

        printf("Do you want to continue [y/n]: ");
        scanf(" %c", &choice);
        if(choice=='n' || choice=='N') break;
    }
}

void display(int adjMat[][100], int vertices){
    for(int i = 0; i<vertices; i++){
        for(int j = 0; j<vertices; j++){
            if(adjMat[i][j]==1){
                printf("Linked Vertices: (%d, %d)\n", i,j);
            }
        }
    }
}

int main(){
    int vertices;
    int adjMat[MAX][MAX] = {0};
    char type;
    printf("Enter the number of vertices for the graph: ");
    scanf("%d",&vertices);
    printf("What kind of graph you want, directional or undirectional [d/u] : ");
    scanf(" %c", &type);
    graph(adjMat,vertices,type);
    display(adjMat,vertices);
    return 0;
}