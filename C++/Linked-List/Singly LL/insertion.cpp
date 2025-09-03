#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList{
    Node* head;
    public:
    LinkedList() { head = nullptr; }
    
    void insertAtBeginning(int val){
        Node * newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
    void insertAtPosition(int val, int pos){
        if (pos == 1){
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i =0; temp != nullptr && i < pos -1; i++){
            temp = temp->next;
        }
        if (temp == nullptr) return;
        newNode-> next = temp->next;
        temp->next = newNode;
    }
    
    void display(){
        Node* temp = head;
        while (temp != nullptr){
            cout<< temp->data<< "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtPosition(25,3);
    
    cout << "Linked List: ";
    list.display();
    
    return 0;
}
