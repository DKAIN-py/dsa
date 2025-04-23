#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000  // Define max stack size

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

bool areBracketsBalanced(char arr[], int len, char stack[], int* top) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{') {
            push(stack, arr[i], top);
        } 
        else if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}') {
            if (isEmpty(*top)) {
                return false;  // More closing brackets than opening brackets
            }

            char popped = pop(stack, top);

            if ((arr[i] == ')' && popped != '(') ||
                (arr[i] == ']' && popped != '[') ||
                (arr[i] == '}' && popped != '{')) {
                return false;  // Fix: should return false, not true
            }
        }
    }

    return isEmpty(*top);
}

int main() {
    int top = -1;
    char* expression = NULL;
    size_t size = 0;

    printf("Enter the expression to be evaluated: ");
    getline(&expression, &size, stdin);

    int len = strlen(expression);

    if (expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
        len--;
    }

    char* stack = (char*)calloc(len, sizeof(char));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    if (areBracketsBalanced(expression, len, stack, &top)) {
        printf("Entered expression is balanced!\n");
    } else {
        printf("Entered expression is unbalanced!\n");
    }


    free(expression);
    free(stack);
    return 0;
}


