#include<stdio.h>

void insertion_sort(int arr[], int len){
    for(int i = 1; i<len; i++){
        int temp = arr[i];
        int j = i - 1;
        int pos = i;
        while(j >= 0){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
                pos--;
            }
            j--;
        }
        arr[pos] = temp;
    }

}

int main(){
    
    int arr[] = {3,7,3,4,4,8};
    insertion_sort(arr, 6);    
    printf("Sorted array : ");
    for(int i = 0; i<6; i++){
        printf("%d,", arr[i]);
    }

    return 0;
}