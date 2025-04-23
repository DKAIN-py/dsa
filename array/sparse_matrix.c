#include<stdio.h>

int main(){
    int sparse[5][4] = {{0, 0, 4, 5},
                        {0, 0, 0, 0},
                        {1, 3, 6, 0},
                        {4, 9, 0, 0},
                        {0, 1, 2, 0}
                        };

    int size = 0;
    for(int i = 0; i<5; i++){
        for(int j = 0; j<4; j++){
            if(sparse[i][j]!=0){
                size++;
            }
        }
    }

    printf("Size of matrix: %d\n", size);
    int triplet[size][3];
    int row = 0;
    for(int i = 0; i<5; i++){
        int column = 0;
        for(int j = 0; j<4; j++){
            if(sparse[i][j]!=0){
                triplet[row][column] = i;
                triplet[row][column+1] = j;
                triplet[row][column+2] = sparse[i][j];
                row++;
            }            
        }
    }

    for(int i = 0; i<size; i++){
        for(int j = 0; j<3; j++){
            printf("%d  ", triplet[i][j]);
        }
        printf("\n");
    }

    return 0;
}