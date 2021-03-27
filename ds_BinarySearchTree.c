#include <stdio.h>
#include <stdlib.h>

typedef struct _BTNode {
    int data;
    struct _BTNode *left;
    struct _BTNode *right;
} BTNode;

BTNode *Root;

BTNode *newNode(int value) {
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

void insertion(int value) {
    BTNode *pre = NULL, *cur = Root;
    while (cur) {
        pre = cur;
        cur = value < cur->data ? cur->left : cur->right;
    }
    if (value < pre->data)
        pre->left = newNode(value);
    else
        pre->right = newNode(value);
}

void inOrder(BTNode *root) {
    if (root) {
        BTNode *node = root;
        inOrder(node->left);
        printf("%d ", root->data);
        inOrder(node->right);
    }
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