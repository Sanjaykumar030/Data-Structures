#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList(int n){
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int value;
    for (int i =0; i < n; i++){
        printf("Enter the value for node %d: ", i +1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        
        if (head == NULL){
            head = newNode;
            temp = head;
        } else{
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    return head;
}

void display(struct Node* head){
    printf("Doubly Linked List: ");
    while (head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
        
    }
    printf("NULL\n");
}

int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    
    struct Node* head = createList(n);
    display(head);
    return 0;
}
