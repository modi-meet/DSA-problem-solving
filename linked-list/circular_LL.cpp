// Circular Linked List
// tail node points to head instead of NULL
#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;
    public:
    CircularList(){
        head=tail=NULL;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
            tail->next = head; //circular property
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
            tail->next = head;
        }

        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }

    void delAtHead(){
        if(head == NULL) return;
        else if (head == tail){
            delete head;
            head = tail = NULL;  
        } else{
            Node* temp = head;
            head = head -> next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        } 
    }

    void delAtTail(){
        if(head == NULL) return;
        else if (head == tail){
            delete head;
            head = tail = NULL;  
        } else {
            Node* temp = tail;
            Node* prev = head; // prev points to the previous node of tail
            while(prev->next != tail) prev = prev->next;
            
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        } 
    }
    
    void print(){
        if(head==NULL) return;
        cout<<head->data<<"->";
        Node* temp = head->next; //***//

        while(temp != head){
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout << temp->data << endl;
    }
};

int main(){
    CircularList cll;

    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3); cll.print();
    cll.insertAtTail(5);
    cll.insertAtTail(6); cll.print();
    cll.delAtHead(); cll.print();
    cll.delAtHead(); cll.print();
    cll.delAtTail(); cll.print();
    return 0;
}
/*
OUTPUT
3->2->1->3
3->2->1->5->6->3
2->1->5->6->2
1->5->6->1
1->5->1
*/