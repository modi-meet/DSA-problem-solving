// Implement a stack using queues.

// Approach 1 : Using 2 queues
class MyStack {
public:
    queue<int> que1;  
    queue<int> que2; // auxiliary queue

    MyStack() {} // contructor
    
    void push(int x) { // O(n)
        while(!que1.empty()){
            que2.push(que1.front());
            que1.pop();
        }
        que1.push(x);
        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
    }
    
    int pop() { // O(1)
        int result = que1.front(); // store before popping
        que1.pop();

        return result;
    }
    
    int top() { // O(1)
        return que1.front();
    }
    
    bool empty() { // O(1)
        return que1.empty();
    }
};

// Follow-up : Using only 1 queue
class MyStack {
public:
    queue<int> que;

    MyStack() { // constructor
    }
    
    void push(int x) {
        que.push(x);
        int n = que.size(); // add the element 'x' and reverse the queue order; 'x' comes at the top 

        for(int i=0; i<n-1; i++){
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int result = que.front();
        que.pop();

        return result;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};