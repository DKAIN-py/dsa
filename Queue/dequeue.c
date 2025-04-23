#include<stdio.h>
#include<stdbool.h>


bool isEmpty(int *size){
    return *size==0;        //O(k)
}

bool isFrontFull(int *front){
    return *front==0;       //O(k)
}

bool isBackFull(int *back, int len){
    return *back==len;          //O(k)
}

void insert(int queue[], int *back, int *front ,int len, int *size){
    

    char choice;
    printf("Where do you want to store the elemnet, front or back (f/b) : ");
    scanf(" %c", &choice);    
    if(choice=='b' || choice=='B'){

        if(isBackFull(back, len)){
            printf("Back is full. Try front.\n");
            return;
        }

        printf("Enter the elemnet you want to store : ");
        scanf("%d", &queue[*back]);

        (*back)++;
    }
                                                                        //O(k)
    else if(choice=='f' || choice=='F'){

        if(isFrontFull(front)){
            printf("front is full. Try back.\n");
            return;
        }
        printf("\nFront before insertion: %d\n", *front);
        printf("Enter the elemnet you want to store : ");
        (*front)--;
        scanf(" %d", &queue[*front]);

        
        printf("\nFront after insertion: %d\n", *front);
    }
    
    (*size)++;

}

void delete(int queue[], int *back, int *front , int *size){
    if(isEmpty(size)){
        printf("Queue is already empty. Underflow occured.\n");
        return;
    }

    char choice;
    printf("From where do you want to delete the elemnet, front or back (f/b) : ");
    scanf(" %c", &choice);
                                                                                        //O(k)
    if(choice=='b' || choice=='B'){(*back)--;}

    else if(choice=='f' || choice=='F'){
        printf("\nFront before updation: %d", *front);
        (*front)++;
        printf("\nFront after updation: %d\n", *front);
    }

    else{printf("No operations permitted for this action.\n");}

    (*size)--;
}

void display(int queue[], int *front, int *back){
    for(int i = *front; i< *back; i++){
        printf("%d, ", queue[i]);
    }                               //O(*size)
    printf("\n");
}



int main(){
    
    int queue[10]={11,12,13,14,15};
    int front = 0;
    int back = 4;
    int size = 5;
    
    int choice;
    display(queue, &front, &back);
    printf("1 for push.\n");
    printf("2 for pop.\n");
    printf("3 to exit.\n");

    while(true){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice==1){      //O(k)
            insert(queue,&back,&front,10,&size); 
            display(queue, &front, &back);

        }

        else if(choice==2){     //O(k)
            delete(queue, &back, &front, &size);
            display(queue, &front, &back);

        }

        else{break;}
    }

    return 0;
}

//worst case time complexity O(n); n=10 in this case