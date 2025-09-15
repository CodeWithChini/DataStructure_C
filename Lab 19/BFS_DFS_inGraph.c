#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

int adj[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int n;

int queue[MAX_VERTICES];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = item;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    } else {
        return queue[front++];
    }
}

void dfs(int vertex) {
    int i;
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int start_node) {
    int i, current_node;

    enqueue(start_node);
    visited[start_node] = 1;

    while (front != -1 && front <= rear) {
        current_node = dequeue();
        printf("%d ", current_node);

        for (i = 0; i < n; i++) {
            if (adj[current_node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start_node;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);

    if (n > MAX_VERTICES || n <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nEnter the starting vertex for DFS: ");
    scanf("%d", &start_node);

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(start_node);
    printf("\n");

    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &start_node);

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    front = -1;
    rear = -1;

    printf("BFS Traversal: ");
    bfs(start_node);
    printf("\n");

    return 0;
}
