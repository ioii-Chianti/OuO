#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

// new a node with value
Node *newNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// create linked list from array
Node *createList(int *arr, int size) {
    Node *head = newNode(arr[0]);
    Node *current = head;
    for (int i = 1; i < size; i++) {
        current->next = newNode(arr[i]);
        current = current->next;
    }
    return head;
}

Node *_createList(int *arr, int size) {
    Node *head = (Node *)malloc(sizeof(Node));
    Node *current = head;
    for (int i = 0; i < size; i++) {
        current->data = arr[i];
        if (i != size - 1) {
            current->next = (Node *)malloc(sizeof(Node));
            current = current->next;
        } else
            current->next = NULL;
    }
    return head;
}

void pushFront(Node **head, int value) {
    Node *node = newNode(value);
    node->next = *head;
    *head = node;
}

void deleteNode(Node **head, int index) {
    Node *toDelete;
    if (!index) {
        toDelete = *head;
        *head = (*head)->next;
    } else {
        Node *previous = NULL, *current = *head;
        while (index--) {
            if (current->next) {
                previous = current;
                current = current->next;    // index = steps forwards
            } else
                return;   // out of range
        }
        toDelete = current;
        previous->next = current->next;
        current = previous->next;
    } free(toDelete);
}

Node *copyList(Node *head) {
    if (!head)
        return NULL;
    Node *node = newNode(head->data);
    node->next = copyList(head->next);
    return node;
}

Node *_copyList(Node *head) {
    Node *copyHead = (Node *)malloc(sizeof(Node));
    Node *node = copyHead;
    while (head->next) {
        node->data = head->data;
        node = node->next = (Node *)malloc(sizeof(Node));
        head = head->next;
    }
    node->data = head->data;
    node->next = NULL;
    return copyHead;
}

void swapData(Node **head, int index1, int index2) {
    Node *node1, *node2;
    node1 = node2 = *head;

    while (index1--)
        node1 = node1->next;
    while (index2--)
        node2 = node2->next;

    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void traversal(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    } printf("\n");
}

int main() {
    int T, size;
    scanf("%d %d", &T, &size);
    int *array = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i)
        scanf("%d", &array[i]);

    Node *head = NULL;
    if (size > 0) {
        head = createList(array, size);
        traversal(head);
    }   // initailize linked list

    int value;
    while (T--) {
        int operation;
        scanf("%d", &operation);
        switch (operation) {
            case 0:
                scanf("%d", &value);
                pushFront(&head, value);
                break;
            case 1: {
                Node *otherHead = copyList(head);
                /* free original list */
                while (head) {
                    Node* toFree = head;
                    head = head->next;
                    free(toFree);
                }
                head = otherHead;
                break;
            } case 2:
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3: {
                int index1, index2;
                scanf("%d%d", &index1, &index2);
                swapData(&head, index1, index2);
            }
        } traversal(head);
    }
    /* free linked list */
    while (head) {
        Node* toFree = head;
        head = head->next;
        free(toFree);
    }
    return 0;
}