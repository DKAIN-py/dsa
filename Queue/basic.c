#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//array implementation

bool isEmpty(int *size){
    return *size == 0;
}

bool isFull(int *size, int len){
    return *size == len;
}

void insert(int queue[], int len ,int *size){
    if(isFull(size,len)){
        printf("Queue is already full. Overflow occured!\n");
        exit(1);
    }
    printf("Enter the data you want to store: ");
    scanf("%d", &(queue[*size]));
    (*size)++;
}

void delte(int queue[], int *size){
    if(isEmpty(size)){
        printf("Queue is empty. Underflow occured!\n");
        exit(1);
    }
    for(int i = 0; i< *size-1; i++){
        queue[i] = queue[i+1];
    }
    (*size)--;
}

void display(int queue[], int *size){
    for(int i = 0; i< *size; i++){
        printf("%d, ", queue[i]);
    }
    printf("\n");
}

int main(){
    int queue[10] = {11,12,13,14,15,16,17};
    int size = 7;
    int choice;
    display(queue, &size);
    printf("1 for intsert.\n");
    printf("2 for delete.\n");
    printf("3 to exit\n");
     
    while(true){
        printf(".....");
        scanf("%d", &choice);
        if(choice==1){
            insert(queue,10, &size);
            display(queue, &size);

        }
        else if(choice==2){
            delte(queue, &size);
            display(queue, &size);

        }
        else{break;}
    }


    return 0;
}