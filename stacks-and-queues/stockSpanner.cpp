// Online Stock Span
// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.
// Implement the StockSpanner class:
// - StockSpanner() Initializes the object of the class.
// - int next(int price) Returns the span of the stock's price given that today's price is price.

class StockSpanner {
public: 
    stack<pair<int, int>> st;

    StockSpanner() {
        st = stack<pair<int, int>>(); // clearing the stack
    }
    
    int next(int price) {
        int span = 1;
        
        while(!st.empty() && st.top().first <= price) {
            auto [prevPrice, prevSpan] = st.top();
            span += prevSpan;
            
            st.pop();
        }
        st.push({price, span});

        return span;
    }
};
// Time Complexity: O(N)