#include <stdio.h>
#include <stdlib.h>

// Queue node structure
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

QueueNode* front = NULL;
QueueNode* rear = NULL;

// Enqueue function
void enqueue(int value) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

// Dequeue function
int dequeue() {
    if (front == NULL)
        return -1;
    QueueNode* temp = front;
    int data = temp->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    return data;
}

// Check if queue is empty
int isEmpty() {
    return front == NULL;
}

// BFS function using adjacency matrix
void bfs(int adjMat[5][5], int vertices, int start) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adjMat[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices = 5;
    int adjMat[5][5] = {
        {0, 1, 0, 1, 0}, // edges from vertex 0 → 1, 3
        {1, 0, 1, 1, 0}, // edges from vertex 1 → 2
        {1, 0, 0, 0, 1}, // edges from vertex 2 → 4
        {1, 1, 0, 0, 1}, // edges from vertex 3 → 1
        {0, 0, 1, 1, 0}  // edges from vertex 4 → 3
    };

    printf("BFS traversal starting from vertex 0:\n");
    bfs(adjMat, vertices, 0);

    return 0;
}
