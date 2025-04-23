#include<stdio.h>
#include<stdlib.h>


void insert(int arr[], int *size, int capacity, int position, int ele){
    if(*size >= capacity){
        printf("Array is already full!! Overflow occured.\n");
        exit(1);
    }

    for(int  i = *size; i>position; i--){
        arr[i] = arr[i-1];
    }

    arr[position] = ele;
    (*size)++;
}

void delete(int arr[], int *size, int capacity, int position){
    if(*size <= 0){
        printf("Underflow occured!!\n");
        exit(1);
    }

    for(int j = position; j < *size; j++){
        arr[j] = arr[j+1];
    }

    (*size)--;
}

void display(int arr[], int size){
    for(int i = 0; i<size; i++){
        printf("%d, ",arr[i]);
    }
    printf("\n\n");
}

void update(int arr[], int capacity ,int position, int ele){
    if(position>capacity){
        printf("Entered position is out bound.\n");
        exit(1);
    }

    arr[position] = ele;
}

int main(){
    int arr[10] = {1,2,4,5,6,7};
    int size = 6, capacity = 10;

    display(arr, size);

    insert(arr, &size, capacity, 2,3);

    display(arr, size);

    delete(arr, &size, capacity, 5);

    display(arr, size);

    update(arr,capacity,4, 90);

    display(arr,size);
    
    return 0;
}