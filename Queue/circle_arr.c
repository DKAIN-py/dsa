#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isEmpty(int *size){
    return *size==0;
}

bool isFull(int len, int *size){
    return *size == len;
}

void insert(int queue[], int len, int *size, int *rear){
    if(isFull(len, size)){
        printf("Queue is already full. Overflow occured!\n");
        exit(1);
    }

    // if(*rear==len){
    //     *rear = 0;
    //     printf("Enter the data you want to store: ");
    //     scanf("%d", &queue[*rear]);
    // }
    
    // else{
    //     (*rear)++;
    //     printf("Enter the data you want to store: ");
    //     scanf("%d", &queue[*rear]);
    // }

    *rear = (*rear +1)%len;
    (*size)++;

}

void delete(int queue[], int *size, int *front,int len){
    if(isEmpty(size)){
        printf("Queue is empty. Underflow occured!\n");
        exit(1);
    }

    // if(*front==len){
    //     *front = 0;
    // }

    // else{
    //     (*front)++;
    // }

    *front = (*front +1)%len;

    (*size)--;
}

void display(int queue[], int len, int *rear, int *front, int *size){
    if(isEmpty(size)){
        printf("Queue is empty. Underflow occured!\n");
        exit(1);
    }
    // if(*front > *rear){
    //     for(int i = *front; i<len; i++){
    //         printf("%d, ", queue[i]);
    //     }
    //     for(int j = 0; j< *rear; j++){
    //         printf("%d, ", queue[j]);
    //     }
    //     printf("\n");
    // }

    // else if(*front == *rear){
    //     printf("%d\n", queue[*front]);
    // }

    // else{
    //     for(int i = *front; i<= *rear ; i++){
    //         printf("%d, ", queue[i]);
    //     }
    //     printf("\n");
    // }

    printf("Queue: ");
    int count = *size;
    int i = *front;
    while(count--) {
        printf("%d ", queue[i]);
        i = (i + 1) % len;
    }
    printf("\n");
}

int main(){
    int queue[7]={11,12,13,14};
    int size = 4;
    int rear = 3;
    int front = 0;
    int choice;
    display(queue,7, &rear, &front, &size);
    printf("1 for intsert.\n");
    printf("2 for delete.\n");
    printf("3 to exit\n");
     
    while(true){
        printf(".....");
        scanf("%d", &choice);
        if(choice==1){
            insert(queue, 7, &size, &rear);
            display(queue,7, &rear, &front, &size);

        }
        else if(choice==2){
            delete(queue, &size, &front, 7);
            display(queue,7, &rear, &front, &size);
        }
        else{break;}
    }
    return 0;
}