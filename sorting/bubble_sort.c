#include<stdio.h>

void bubble_sort(int arr[], int len){
    for(int i = 0; i<len-1; i++){
        for(int j = 0; j+1 < len-i ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {3,7,5,4,9,8};
    bubble_sort(arr, 7);    
    printf("Sorted array : ");
    for(int i = 0; i<6; i++){
        printf("%d,", arr[i]);
    }
    return 0;
}