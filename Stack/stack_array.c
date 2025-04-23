#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXLEN  100

typedef struct {
    int data[MAXLEN];
    int top;
} Stack;

void init(Stack *s){
    s->top = -1;
}

bool isFull(Stack *s){
    return s->top == MAXLEN -1;
}

bool isEmpty(Stack *s){
    return s->top == -1;
}

void push(Stack *s){
    if(isFull(s)){
        printf("Overflow occured!!\n");
        exit(1);
    }
    printf("Enter the data to be stored: ");
    (s->top)++;
    scanf("%d", &(s->data[s->top]));
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Underflow occured!!\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("Underflow occured!!\n");
        exit(1);
    }
    int pos;
    printf("Enter the index at which you want to peek: ");
    scanf("%d", &pos);
    if(pos<=(s->top) || pos>=0){
        printf("Data at %d = %d \n", pos, s->data[pos]);
    }
    else{
        printf("Either index provided is less than 0 or there isn't any data present at index\n");
    }
}

void display(Stack *s){
    if(isEmpty(s)){
        printf("Underflow occured!!\n");
        exit(1);
    }
    for(int i = 0; i <= s->top; i++){
        printf("Data at %dth index = %d \n", i+1, s->data[i]);
    }
}

int main(){
    Stack stack;
    int choice;
    init(&stack);
    push(&stack);
    push(&stack);
    push(&stack);
    display(&stack);
    printf("What do you want to do?\n");
    printf("1 for push\n");
    printf("2 for pop\n");
    printf("3 for peek\n");
    printf("4 for display\n");
    printf("5 to end\n");
    while(choice!=5){
        printf("\n....");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                push(&stack);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(&stack);
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                break;
            default:
                printf("Operation not defined. Try something else\n");
        }
    }
    return 0;
}