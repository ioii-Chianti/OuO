#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXEXPR 260   // 最長的輸入
#define MAXSYM 6   // 最多幾個運算園

char expr[MAXEXPR];
int pos;

typedef struct _BTNode {
    char data;
    struct _BTNode *left;
    struct _BTNode *right;
} BTNode;

BTNode *newNode(char ch) {
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->data = ch;
    node->left = node->right = NULL;
    return node;
}

BTNode *Expression() {
    char ch;
    BTNode *node = NULL, *right = NULL;
    if (pos >= 0) {
        ch = expr[pos--];
        if ('A' <= ch && ch <= 'D')
            right = newNode(ch);
            
        if (pos > 0) {
            ch = expr[pos];
            if (ch == '|' || ch == '&') {
                node = newNode(ch);
                node->right = right;
                pos--;
                node->left = EXPR();
            } else
                node = right;
        } else
            node = right;
    }
    return node;
}

int main() {
    while (scanf("%s", expr) != EOF) {
        pos = strlen(expr) - 1;
        BTNode *Root = Expression();
        preOrder(Root);
    }
    return 0;
}