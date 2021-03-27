#include <stdio.h>
#include <stdlib.h>

typedef struct _BTNode {
    int data;
    struct _BTNode *left;
    struct _BTNode *right;
} BTNode;

int height;
BTNode *Root;

BTNode *newNode(int value) {
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// just for insert nodes; faster
void insertNode(int value) {
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

// insert node recursively; more detail for level info.
void insertNode_Rec(BTNode **root, int value, int level) {
    // empty position is found, renew info. of this level
    if (*root == NULL) {
        *root = newNode(value);
        if (height < level)
            height = level;
        // sums[level] += value;
        // nodes[level]++;
    }
    // find a right position for new node recursively, level increases sue to every recursion
    else {
        if (value < (*root)->data)
            return insertNode_Rec(&((*root)->left), value, level + 1);
        else if ((*root)->data < value)
            return insertNode_Rec(&((*root)->right), value, level + 1);
    }
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
            insertNode(input);
    }
    inOrder(Root);
    return 0;
}