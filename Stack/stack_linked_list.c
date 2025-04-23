#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* node;

bool isEmpty(node top) {
    return top == NULL;
}

void push(node* top) {
    node new_node = (node)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the data to be stored: ");
    scanf("%d", &new_node->data);

    new_node->next = *top;
    *top = new_node;
}

void pop(node* top) {
    if (isEmpty(*top)) {
        printf("Underflow occurred!!\n");
        return;
    }

    node temp = *top;
    *top = (*top)->next;
    free(temp);
}

void peek(node top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

void display(node top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }

    node temp = top;
    int pos = 0;

    while (temp != NULL) {
        printf("(%d) Data: %d\n", pos, temp->data);
        temp = temp->next;
        pos++;
    }
}

int stacklen(node top) {
    int len = 0;
    node temp = top;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }

    return len;
}

void memoryfree(node* top) {
    node temp;

    while (*top != NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main() {
    node top = NULL;
    int choice;

    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1 for push\n");
        printf("2 for pop\n");
        printf("3 for peek\n");
        printf("4 for display\n");
        printf("5 to end\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&top);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            case 5:
                memoryfree(&top);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}