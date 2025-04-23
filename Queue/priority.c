#include<stdio.h>
#include<stdbool.h>

bool isEmpty(int *size){
    return *size==0;
}

bool isFull(int *size, int len){
    return *size==len;
}

void insert(int data_queue[], int priority_queue[], int *size, int *top, int len){
    if(isFull(size, len)){
        printf("Queue is full. Overflow occured.\n");
        return;
    }

    printf("Enter the element to be stored: ");
    scanf("%d", &data_queue[*size]);
    printf("Enter the priority of this element: ");
    scanf("%d", &priority_queue[*size]);

    if(priority_queue[*size]>priority_queue[*top]){
        *top = *size;
    }

    (*size)++;

}

void pop_higest(int data_queue[], int priority_queue[], int *size, int *top){
    if(isEmpty(size)){
        printf("Queue is empty. Underflow occured.\n");
        return;
    }

    for(int i = *top; i< *size-1; i++){
        data_queue[i] = data_queue[i+1];
        priority_queue[i] = priority_queue[i+1];
    }

    (*size)--;

    // Step 2: Recalculate new top
    if (*size == 0) {
        *top = -1;
        return;
    }

    *top = 0;
    for (int i = 1; i < *size; i++) {
        if (priority_queue[i] > priority_queue[*top]) { // or < if lower is higher priority
            *top = i;
        }
    }
    

}

void peek(int data_queue[], int *top, int *size){
    if(isEmpty(size)){
        printf("Queue is empty. No top found.\n");
        return;
    }

    printf("Top elemnt is: %d\n\n", data_queue[*top]);
}

void display(int data_queue[], int priority_queue[], int *size){
    for(int i = 0; i<*size; i++){
        printf("Data entry: %d\n", data_queue[i]);
        printf("Priority of element: %d\n\n", priority_queue[i]);
    }
}


int main(){
    int dataqueue[10]={11,12,13,14,15,16};
    int prioqueue[10]={2,3,1,5,1,3};    
    int size = 6, top = 3;
    int choice;
    display(dataqueue,prioqueue,&size);
    printf("1 for insert.\n2 for pop highest priority.\n3 to see the top.\nAny other to quit.\n");
    while(true){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice==1){
            insert(dataqueue,prioqueue,&size,&top,10);
            display(dataqueue,prioqueue,&size);
        }

        else if(choice==2){
            pop_higest(dataqueue,prioqueue,&size,&top);
            display(dataqueue,prioqueue,&size);
        }

        else if(choice==3){
            peek(dataqueue,&top,&size);
            display(dataqueue,prioqueue,&size);
        }

        else{break;}
    }
    return 0;
}