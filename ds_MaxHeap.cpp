#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#define DEBUG 1
using namespace std;

/* Class Declaraion */

class MaxHeap {
    public:
        // constructor: init attribute (Cnt = 0)
        MaxHeap() : Cnt(0) {}
        virtual ~MaxHeap() {}
        virtual void PUSH(const int &) = 0;
        virtual int MAX() const = 0;
        virtual int POP() = 0;
        int getCnt() const { return Cnt; }
        // An empty tree has height of 0. A tree with only root node has height of 1.

    protected:
        int Cnt;
};

class MaxHeapArray : public MaxHeap {
    // root node is stored at index 1.
    public:
        MaxHeapArray();
        virtual ~MaxHeapArray() {}
        virtual void PUSH(const int &) override;
        virtual int MAX() const override;
        virtual int POP() override;
        void printArray() const;
    
    private:
        int array[1025];
        void HeapifyArray(int *, int, const string);
};

class Node {
    friend class MaxHeapList; // MaxHeapList can access Node

    public:
        // constructor: init attributes (value = info, left = right = parent = NULL)
        Node(const int &info) : value(info), left(NULL), right(NULL), parent(NULL) {}
        int getValue() const { return value; }
        Node *getLeft() const { return left; }
        Node *getRight() const { return right; }

    private:
        int value;
        Node *left;
        Node *right;
        Node *parent;
};

class MaxHeapList : public MaxHeap {
    public:
        MaxHeapList();
        virtual ~MaxHeapList() { deleteTree(Root); }
        virtual void PUSH(const int &) override;
        virtual int MAX() const override;
        virtual int POP() override;
        void preOrder(Node *) const;
        void inOrder(Node *) const;

    private:
        Node *Root;
        void deleteTree(Node *root);
        Node *findparent(int cnt, Node *root) {   // find the parent of node cnt
            if (cnt <= 1) return root;
            string s = "";
            while (cnt != 0) {
                s += cnt % 2 + '0';
                cnt /= 2;
            }
            Node *now = root;
            for (int i = 1; i < s.size() - 1; i++) {
                if (s[i] == '0')
                    now = now->left;
                else
                    now = now->right;
            }
            return now;
        }
        void HeapifyList(Node *, const string);
};

int main() {
    MaxHeapArray arrayHeap;
    MaxHeapList listHeap;
    
    string operation;
    int T, toPush;
    cin >> T;
    while (T--) {
        cin >> operation;
        if (operation == "arr_push") {
            cin >> toPush;
            arrayHeap.PUSH(toPush);
        } else if (operation == "list_push") {
            cin >> toPush;
            listHeap.PUSH(toPush);
        } else if (operation == "max") {
            cout << arrayHeap.MAX() << endl;
            cout << listHeap.MAX() << endl;
        } else if (operation == "arr_pop") {
            cout << arrayHeap.POP() << endl;
        } else if (operation == "list_pop") {
            cout << listHeap.POP() << endl;
        } else if (operation == "size") {
            cout << arrayHeap.getCnt() << endl;
            cout << listHeap.getCnt() << endl;
        }
    }
}

/* Class Definition: MaxHeapArray */

// reusing base constructor to init Cnt = 0
MaxHeapArray::MaxHeapArray() : MaxHeap() { memset(array, -1, sizeof(array)); }

void MaxHeapArray::PUSH(const int &item) {
    array[++Cnt] = item;
    HeapifyArray(array, Cnt, "push");
    if (DEBUG) printArray();
}

int MaxHeapArray::MAX() const { return array[1]; }

int MaxHeapArray::POP() {
    if (!Cnt)
        return -1;
    int ret = array[1];
    array[1] = array[Cnt];
    array[Cnt--] = -1;
    HeapifyArray(array, 1, "pop");
    if (DEBUG) printArray();
    return ret;
}

void MaxHeapArray::HeapifyArray (int *arr, int index, const string operation) {
    if (operation == "push") {
        // current node is root
        if (index == 1)
            return;
        // if: swap, else: already on right position
        if (arr[index] > arr[index / 2]) {
            int temp = arr[index];
            arr[index] = arr[index / 2];
            arr[index / 2] = temp;
            HeapifyArray(arr, index / 2, "push");
        } else
            return;
    } else if (operation == "pop") {
        // current node is leaf
        if (index * 2 == -1 && index * 2 + 1 == -1)
            return;
        
        // current node has at least one child
        // find the index of bigger child
        int bigChild = arr[index * 2] > arr[index * 2 + 1] ? index * 2 : index * 2 + 1;
        // if: swap, else: already on right position
        if (arr[index] < arr[bigChild]) {
            int temp = arr[index];
            arr[index] = arr[bigChild];
            arr[bigChild] = temp;
            HeapifyArray(arr, bigChild, "pop");
        } else
            return;
    }
}

void MaxHeapArray::printArray() const {
    for (int i = 1; i <= Cnt; i++)
        cout << array[i] << " ";
    cout << endl;
}


/* Class Definition: MaxHeapList */

// constructor: init attribute (Root = NULL)
MaxHeapList::MaxHeapList() : Root(NULL) {}

void MaxHeapList::PUSH(const int &value) {
    if (!Cnt)
        Root = new Node(value);
    else {
        // find the parent of new node
        Node *toHeapify, *pivot = findparent(Cnt + 1, Root);
        if (DEBUG) cout << "--- Parent: " << pivot->value << endl;
        
        // decide left or right position to push node
        if (pivot->left == NULL) {
            pivot->left = new Node(value);
            pivot->left->parent = pivot;
            toHeapify = pivot->left;
        } else {
            pivot->right = new Node(value);
            pivot->right->parent = pivot;
            toHeapify = pivot->right;
        }
        HeapifyList(toHeapify, "push");
    }
    Cnt++;
    if (DEBUG) {
        cout << "--- preOrder: ";
        preOrder(Root);
        cout << endl;
        cout << "--- inOrder: ";
        inOrder(Root);
        cout << endl;
    }
}

int MaxHeapList::MAX() const { return Root ? Root->value : -1; }

int MaxHeapList::POP() {
    if (!Cnt)
        return -1;
    int ret = Root->value;
    if (Cnt == 1)
        Root = NULL;
    else {
        Node *toHeapify = Root, *pivot = findparent(Cnt, Root);
        // decide left or right position to pop node
        if (pivot->right) {
            Root->value = pivot->right->value;
            pivot->right = NULL;
        } else {
            Root->value = pivot->left->value;
            pivot->left = NULL;
        }
        HeapifyList(toHeapify, "pop");
    }
    Cnt--;
    if (DEBUG) {
        cout << "--- preOrder: ";
        preOrder(Root);
        cout << endl;
        cout << "--- inOrder: ";
        inOrder(Root);
        cout << endl;
    }
    return ret;
}

void MaxHeapList::HeapifyList(Node *toHeapify, const string operation) {
    if (operation == "push") {
        while (toHeapify != Root) {
            if (toHeapify->value > toHeapify->parent->value) {
                int numA = toHeapify->value, numB = toHeapify->parent->value;
                toHeapify->value = numB;
                toHeapify->parent->value = numA;
                if (DEBUG) cout << "--- exchange: " << numA << " & " << numB << endl;
            }
            toHeapify = toHeapify->parent;
        }
    } else if (operation == "pop") {
        while (true) {
            // current node is leaf
            if (toHeapify->left == NULL && toHeapify->right == NULL)
                break;

            // current node has only left child
            if (toHeapify->right == NULL) {
                if (toHeapify->value < toHeapify->left->value) {   // 且現在跟左子要交換
                    int numA = toHeapify->value, numB = toHeapify->left->value;
                    toHeapify->value = numB;
                    toHeapify->left->value = numA;
                    if (DEBUG) cout << "--- exchange: " << numA << " & " << numB << endl;
                }
                break;   // 無論這次有無交換都不會有下一次判斷交換
            }

            // current node has two child
            if (toHeapify->left != NULL && toHeapify->right != NULL) {
                // find the bigger child
                Node *bigChild = toHeapify->left->value > toHeapify->right->value ? toHeapify->left : toHeapify->right;
                // if: swap, else: already on right position
                if (toHeapify->value < bigChild->value) {
                    int numA = toHeapify->value, numB = bigChild->value;
                    toHeapify->value = numB;
                    bigChild->value = numA;
                    toHeapify = bigChild;  // 繼續往下判斷
                    if (DEBUG) cout << "--- exchange: " << numA << " & " << numB << endl;
                } else
                    break;
            }
        }
    }
}

void MaxHeapList::preOrder(Node *root) const {
    if (!root) return;
    cout << root->getValue() << " ";
    preOrder(root->getLeft());
    preOrder(root->getRight());
}

void MaxHeapList::inOrder(Node *root) const {
    if (!root) return;
    inOrder(root->getLeft());
    cout << root->getValue() << " ";
    inOrder(root->getRight());
}

void MaxHeapList::deleteTree(Node *root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}