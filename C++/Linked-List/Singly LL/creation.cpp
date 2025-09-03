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

Node* createList(int n){
    Node* head = nullptr;
    Node* temp = nullptr;
    int value;
    
    for (int i =0; i < n; i++){
        cout<< "Enter value for node " << i + 1 << ": ";
        cin >> value;
        Node* newNode = new Node(value);
        
        if (head == nullptr){
            head = newNode;
            temp = head;
        } else{
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}


void display(Node* head){
    cout << "Linked List: ";
    while (head != nullptr){
        cout << head->data << "-> ";
        head = head->next;
    }
    cout << "Null" << endl;
}

int main(){
    int n;
    cout << "Enter number of nodes: ";
    cin >>n;
    Node* head = createList(n);
    display(head);
    return 0;
}
