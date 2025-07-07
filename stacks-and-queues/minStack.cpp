// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Appraoach - 1
class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() { } // constructor

    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        } else{
            int minVal = min(st.top().second, val);
            st.push({val, minVal});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
// Time Complexity: O(1), Space Complexity : O(2*n) (for stack of pairs)

// Approach - 2
class MinStack {
public:
    stack<int> st;
    int mini = INT_MAX;

    MinStack() { } // constructor

    void push(int val) {
        if(st.empty()){
            st.push(mini = val);
        } else{
            if(val > mini) st.push(val); // value is greater
            else{ // value is lesser; mini is going to be changed
                // Store the difference between the new value and the current minimum
                st.push(val*2 - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;

        if(s.top() < minVal){ // it is not possible to get the minimum value; it must be the previous minimum
            // hence, restore the previous minimum
            minVal = 2*minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(st.top() > mini) return st.top(); 
        return mini; 
    }
    
    int getMin() {
        return mini;
    }
};
// Time Complexity: O(1), Space Complexity : O(n) (for stack of integers)