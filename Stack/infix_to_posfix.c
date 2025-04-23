#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000  // Define max stack size

struct Precedence {
    char oper;
    int precedence;
};

bool isEmpty(int top) {
    return top == -1;
}

void push(char arr[], char ele, int* top) {
    arr[++(*top)] = ele;
}

char pop(char arr[], int* top) {
    if (isEmpty(*top)) {
        printf("Underflow occurred!\n");
        exit(1);
    }
    return arr[(*top)--];
}



int main(){

    struct Precedence list[] = {
        {'-',1},
        {'+',2},
        {'*',3},
        {'/',4},
    };

    int size = sizeof(list)/sizeof(list[0]);

}