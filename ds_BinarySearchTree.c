#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *left;
    struct _Node *right;
} Node;

Node *Root;

Node *newNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

void insertion(int value) {
    Node *pre = NULL, *cur = Root;
    while (cur) {
        pre = cur;
        cur = value < cur->data ? cur->left : cur->right;
    }
    if (value < pre->data)
        pre->left = newNode(value);
    else
        pre->right = newNode(value);
}

void inOrder(Node *root) {
    if (root == NULL)
        return;
    Node *node = root;
    inOrder(node->left);
    printf("%d ", root->data);
    inOrder(node->right);
}

int main() {
    int n, input;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        if (i == 0)
            Root = newNode(input);
        else
            insertion(input);
    }
    inOrder(Root);
    return 0;
}