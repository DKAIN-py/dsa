#include<stdio.h>

void desc_selection_sort(int arr[], int len){
    for(int i = 0; i<len-1; i++){
        for(int j = i+1; j<len; j++){
            if(arr[j] > arr[i]){
                int temp = arr[j] ;
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}



int main(){
    int arr[] = {3,7,5,4,9,8};
    desc_selection_sort(arr, 6);    
    printf("Sorted array in descending form : ");
    for(int i = 0; i<6; i++){
        printf("%d,", arr[i]);
    }
    return 0;
}