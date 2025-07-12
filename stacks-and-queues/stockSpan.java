// Online Stock Span
// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

class StockSpanner {
    List<Integer> spans;

    public StockSpanner() {
        spans = new ArrayList<>();
    }
    
    public int next(int price) {
        spans.add(price);

        int currMaxConsecDays = 1;
        for(int i=spans.size()-2; i>=0; i--){
            if(spans.get(i) > price) break;
            
            currMaxConsecDays++;
        }
        
        return currMaxConsecDays;
    }
}
// Time Complexity: O(n), Space Complexity: O(no. of Next calls)

class StockSpanner {
    Stack<Pair<Integer, Integer>> st;
    int idx;

    public StockSpanner() {
        st = new Stack<>();
        idx = -1;
    }
    
    public int next(int price) {
        idx++;
        
        while(!st.isEmpty() && st.peek().getKey() <= price) st.pop();

        int maxConsecDays = idx - (st.isEmpty() ? -1 : st.peek().getValue());
        st.push(new Pair<>(price, idx));
        
        return maxConsecDays;
    }
}
// Time Complexity: O(2*n) (overall), Space Complexity: O(n)