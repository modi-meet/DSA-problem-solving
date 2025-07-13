// Design Circular Deque

// Using Array
class MyCircularDeque {
public:
    vector<int> arr;
    int k_;
    int front, back;
    int curr_size;

    MyCircularDeque(int k) {
        arr.resize(k);
        front = 0; back = k-1;
        k_ = k;
        curr_size = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        front = (front - 1 + k_) % k_;
        arr[front] = value;
        curr_size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        back = (back + 1) % k_;
        arr[back] = value;
        curr_size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        front = (front+1) % k_;
        curr_size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;

        back = (back-1+k_) % k_;
        curr_size--;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int getRear() {
        return isEmpty() ? -1 : arr[back];
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