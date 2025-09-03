#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int pos){
    if (pos == 1) return insertAtBeginning(head, data);
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    
    for (int i =1; temp != NULL && i < pos -1; i++){
        temp = temp->next;
    }
    if (temp == NULL) return head;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void display(struct Node* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtPosition(head, 25, 3);
    
    display(head);
    return 0;
}
