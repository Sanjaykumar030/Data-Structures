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

struct Node* deleteBeginning(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteEnd(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) return deleteBeginning(head);

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) return head;

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

struct Node* deleteByValue(struct Node* head, int key) {
    if (head == NULL) return NULL;
    if (head->data == key) return deleteBeginning(head);

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == NULL) return head;

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Original: ");
    display(head);

    head = deleteBeginning(head);
    head = deleteEnd(head);
    head = deleteByValue(head, 20);

    printf("After deletions: ");
    display(head);
    return 0;
}
