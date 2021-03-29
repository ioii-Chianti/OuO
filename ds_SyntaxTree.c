#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXEXPR 260

/* Build by infix: EXPR + FAC 
   Build by prefix: newTree */

typedef struct _BTNode {
    char data;
    struct _BTNode *left;
    struct _BTNode *right;
} BTNode;

char expr[MAXEXPR];  // input expression
int pos;             // current position of parsing
BTNode *Expression();
BTNode *Factor();

BTNode *newNode(char ch) {
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->data = ch;
    node->left = node->right = NULL;
    return node;
}

// Build a tree by prefix
BTNode *newTree(BTNode *root) {
    char input;
    scanf("%c", &input);

    if (input == '&' || input == '|') {
        BTNode *node = newNode(input);
        node->left = newTree(node->left);
        node->right = newTree(node->right);
        return node;
    } else {
        BTNode *node = newNode(input);
        return node;
    }
}

BTNode *Expression() {
    char ch;
    BTNode *root = NULL, *right = NULL;
    if (pos >= 0) {

        // 判斷為運算元或是括號
        right = Factor();

        // 取得right後再繼續往前處理 (factor裡會將pos往前)
        if (pos > 0) {
            ch = expr[pos];

            // 是運算子的話把其變成root並把right接上
            if (ch == '|' || ch == '&') {
                root = newNode(ch);
                root->right = right;
                pos--;     // 繼續往前
                root->left = Expression();  // 遞迴處理left
            } else
                root = right;
        } else
            root = right;   // pos == 0 回傳最後一個變數一路往上給left (LINE 43)
    }
    return root;
}

BTNode *Factor() {
    char ch;
    BTNode *node = NULL;
    if (pos >= 0) {

        // 原本的無括號版，先存著運算元回傳給right
        ch = expr[pos--];
        if ('A' <= ch && ch <= 'D')
            node = newNode(ch);          

        // 若是括號則進入Expression，先種出括號內的小樹在回傳給ex的right
        else if (ch == ')') {
            node = Expression();

            if (expr[pos--] != '(')
                printf("Error!\n");
                // 處理完應為左括號
        }
    }
    return node;
}

// prefix taversal
void preOrder(BTNode *root) {
    if (root) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// infix traversal w/ necessary parentheses
void inOrder(BTNode *root) {
    if (root) {
        inOrder(root->left);
        printf("%c", root->data);
        if (root->right) {   // 是運算子的話則需要印括號再進去遞迴子樹
            if (root->right->data == '&' || root->right->data == '|') {
                printf("(");
                inOrder(root->right);
                printf(")");
            } else
                inOrder(root->right);
        }
    }
}

int main() {
    while (scanf("%s", expr) != EOF) {
        pos = strlen(expr) - 1;
        BTNode *Root = Expression();
        preOrder(Root);
    }
    return 0;
}