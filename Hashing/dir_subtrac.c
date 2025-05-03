#include<stdio.h>
#define TABLE_SIZE 11

void inithash(int table[]){
    for(int i =0; i<TABLE_SIZE;i++){
        table[i] = -1;
    }
}

void display(const char *str , int table[]){
    printf("Hash Table using %s\n", str);
    for(int i = 0; i<TABLE_SIZE; i++){
        printf("Index %2d: %d\n", i, table[i]);
    }
}

// Direct method
// The key itself becomes the hash value
void direct_hash(int key[], int len){
    int table[TABLE_SIZE];
    inithash(table);
    for(int i = 0; i<len; i++){
        int index = key[i];
        if(index<TABLE_SIZE){
            table[index] = index;
        }
    }

    display("Direct Hashing", table);
}


// Subtraction method
// hash value = TABLE_SIZE - k ; where k is the key 
void sub_hash(int key[], int n){
    int table[TABLE_SIZE];
    inithash(table);
    for(int i = 0; i<n; i++){
        if(key[i]<=TABLE_SIZE){
            int index = TABLE_SIZE - key[i];
            table[index] = key[i];
        }
    }

    display("Subtracting Method", table);
}



int main(){
    int keys[] = {12,3,4,65,10};
    
    direct_hash(keys,5);

    sub_hash(keys,5);
    return 0;
}