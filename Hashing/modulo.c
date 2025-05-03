#include<stdio.h>
#define TABLE_SIZE 11

void init(int table[]){
    for(int i = 0; i<TABLE_SIZE; i++){
        table[i]=-1;
    }
}

void modulo_hash(int keys[], int len){
    int table[TABLE_SIZE];
    init(table);

    for(int i = 0; i<len; i++){
        if(keys[i]>=0){
            int index = keys[i]%TABLE_SIZE;
            table[index] = keys[i];
        }
    }

    printf("Hashing using Modulo-division:\n");
    for(int i = 0; i<TABLE_SIZE; i++){
        printf("Index %2d: %d\n", i, table[i]);
    }
}

int main(){
    int keys[] = {12,3,4,65,10};
    modulo_hash(keys,5);
    return 0;
}