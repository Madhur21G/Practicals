#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int front, rear, size;
    int *arr;
};
typedef struct Queue queue;
int isEmpty(queue *q){
    if (q->front == q->rear){
        return 1;
    }
    return 0;
}
int isFull(queue *q){
    if (q->rear == q->size - 1) return 1;
    return 0;
}
void enqueue(queue *q, int val){
    if (isFull(q)){
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
}
int dequeue(queue *q){
    int a = -1;
    if (isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

void BFS(int a[7][7], int visited[7], queue q){
    int i = 0;
    printf("BFS Traversal: ");
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);
    while (!isEmpty(&q)){
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++){
            if (a[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    printf("\n");
    return;
}
void DFS(int i, int a[7][7], int visited[7]){
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++){
        if (a[i][j] == 1 && !visited[j]){
            DFS(j, a, visited);
        }
    }
}
int main(){
    queue q;
    q.size = 30;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 0, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1},
    };
    BFS(a, visited, q);
    for (int i = 0; i < 7; i++){
        visited[i] = 0;
    }
    printf("DFS Traversal: ");
    DFS(0, a, visited);
    printf("\n");
    return 0;
}
