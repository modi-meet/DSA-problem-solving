// Fundamental understanding Linked Lists using classes and user-defined functions
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){ //class constructor
        data=val;
        next=NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){ //adds the new node to start/head of the LL
        Node* newNode = new Node(val);
        if(head==NULL) {
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void printLL(){ //printing the LL
        Node* temp = head;
        
        while(temp != NULL){
            cout << temp -> data << "->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void push_back(int val){ //adds the new node to end/tail of the LL
        Node* newNode = new Node(val);
        if(head==NULL) {
            head = tail = newNode;
            return;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){ //removes a node from start/head of the LL
        if(head==NULL) return;

        Node* temp = head;
        head = head -> next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){ //removes a node from end/tail of the LL
        if(head==NULL) return;

        Node* temp = head;
        while(temp -> next != tail){
            temp = temp->next;
        }
        temp -> next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos){ // value, index
        if(pos<0)return;
        if(pos==0) {
            push_front(val); 
            return;
        }

        Node* temp = head;
        for(int i=0 ; i<pos-1; i++){
            if(temp == NULL) return;
            temp=temp->next;
        } 

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next= newNode;
    }

    int search(int key){
        Node* temp = head;
        int idx=0;
        while(temp != NULL){
            if(temp->data == key) return idx;
              temp=temp->next;
              idx++;
        }
        return -1;
    }
};

int main(){
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3); ll.printLL();

    ll.push_back(4); ll.printLL();
    ll.pop_front(); ll.printLL();
    ll.pop_back(); ll.printLL();

    ll.insert(4,1); ll.printLL();
    cout<<ll.search(1)<<endl;
    return 0;
}

/*
OUTPUT : 
3->2->1->NULL
3->2->1->4->NULL
2->1->4->NULL
2->1->NULL
2->4->1->NULL
2
*/