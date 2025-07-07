// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
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