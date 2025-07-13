// Design Circular Queue (Without using STL queue<> Data Structure)

// Approach-1 : using Array
class MyCircularQueue {
public:
    vector<int> arr;
    int k_;
    int front = 0, back = -1;
    int curr_size = 0;

    MyCircularQueue(int k) {
        arr.resize(k);
        k_ = k;
    }
    
    bool enQueue(int value) {
        if(curr_size == k_) return false;

        back = (back+1) % k_;
        arr[back] = value;
        curr_size++;

        return true;
    }
    
    bool deQueue() {
        if(curr_size == 0) return false;

        front = (front+1) % k_;
        curr_size--;
        
        return true;
    }
    
    int Front() {
        if(curr_size == 0) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(curr_size == 0) return -1;
        return arr[back];
    }
    
    bool isEmpty() {
        return curr_size == 0;
    }
    
    bool isFull() {
        return curr_size == k_;
    }
}; 
// Time Complexity: O(1) for all operations
// Space Complexity: O(k)

// Approach-2 : Using Linked List
class MyCircularQueue {
private: 
    // Linked List structure
    struct Node{
        int val;
        Node* next;

        Node(int value){
            val = value;
            next = NULL;
        }
    };
public:
    int k_;
    Node* front;
    Node* back;
    int curr_size = 0;

    MyCircularQueue(int k) {
        front = back = NULL;
        k_ = k;
    }
    
    bool enQueue(int value) {
        if(curr_size == k_) return false;

        Node* newNode = new Node(value);
        if(curr_size == 0){
            front = back = newNode;
            back->next = front; // circular property
        } else { // nodes already exists
            back->next = newNode;
            newNode->next = front;
            back = back->next;            
        }

        curr_size++;
        return true;
    }
    
    bool deQueue() {
        if(curr_size == 0) return false;

        if(curr_size == 1){
            delete front;
            front = back = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            back->next = front;
            delete temp;
        }
        
        curr_size--;
        return true;
    }
    
    int Front() {
        if(curr_size == 0) return -1;

        return front->val;
    }
    
    int Rear() {
        if(curr_size == 0) return -1;

        return back->val;
    }
    
    bool isEmpty() {
        return curr_size == 0;
    }
    
    bool isFull() {
        return curr_size == k_;
    }
};
// Time Complexity: O(1) for all operations
// Space Complexity: O(k)