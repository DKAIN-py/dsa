#include<stdio.h>
#include<stdlib.h>

int visit[5];
int adjMat[5][5] = {
        {0, 1, 0, 1, 0}, // edges from vertex 0 → 1, 3
        {1, 0, 1, 1, 0}, // edges from vertex 1 → 2
        {1, 0, 0, 0, 1}, // edges from vertex 2 → 4
        {1, 1, 0, 0, 1}, // edges from vertex 3 → 1
        {0, 0, 1, 1, 0}  // edges from vertex 4 → 3
};

void DFS(int i){
    int j;
    printf("%d ",i);
    visit[i] = 1;
    for(int j = 0; j<5; j++){
        if(adjMat[i][j]==1 && !visit[j]){
            DFS(j);
        }
    }
}
int main(){
    DFS(0);
    return 0;
}