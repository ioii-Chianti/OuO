#include <stdio.h>
#include <stdlib.h>
#define MAX 5005

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

typedef struct {
    int numVertex;
    Node **adjList;
} Graph;

Graph *graph;
int degree[MAX];

Node *newNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

Graph *newGraph(int num) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertex = num;
    graph->adjList = (Graph **)malloc(num * sizeof(Graph *));
    for (int i = 0; i < num; i++)
        graph->adjList[i] = NULL;   // init each head of linked list
    return graph;
}

// graph.adj[i] equals to different heads!
// operation remains the same
void newEdge(int x, int y) {
    Node *node = newNode(y);
    node->next = graph->adjList[x];
    graph->adjList[x] = node;

    node = newNode(x);
    node->next = graph->adjList[y];
    graph->adjList[y] = node;

    degree[x]++, degree[y]++;
}

void traversal() {   // same as linked list traversal
    for (int vertex = 0; vertex < graph->numVertex; vertex++) {
        Node *node = graph->adjList[vertex];
        printf("%d: ", vertex);
        while (node) {
            printf("%d -> ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    int num_v, vx, vy;
    scanf("%d", &num_v);
    graph = newGraph(num_v);
    while (--num_v) {
        scanf("%d%d", &vx, &vy);
        newEdge(vx, vy);
    }
    traversal();

    return 0;
}