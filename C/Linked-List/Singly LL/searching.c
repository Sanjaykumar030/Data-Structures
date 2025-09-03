#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int search(struct Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) return pos;
        head = head->next;
        pos++;
    }
    return -1; // not found
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    int key = 20;
    int pos = search(head, key);

    if (pos != -1)
        printf("Element %d found at position %d\n", key, pos);
    else
        printf("Element %d not found\n", key);

    return 0;
}
