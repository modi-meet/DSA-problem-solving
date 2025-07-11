// Largest Rectangle in Histogram
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Approach 1 - Pre Compute PSE & NSE
class Solution {
    public int largestRectangleArea(int[] ht) {
        int n = ht.length;
        int maxArea = 0;

        int[] pse = new int[n];
        int[] nse = new int[n];
        Stack<Integer> st = new Stack<>(); // *all 3 - stores Indices of ht array

        for(int i=0; i<n; i++){ //previous smaller element
            while(!st.isEmpty() && ht[st.peek()] >= ht[i])
                st.pop();

            pse[i] = st.isEmpty() ? -1 : st.peek();
            st.push(i); // stack contains indices
        }

        st.clear();

        for(int i=n-1; i>=0; i--){ //next smaller element
            while(!st.isEmpty() && ht[st.peek()] >= ht[i])
                st.pop();

            nse[i] = st.isEmpty() ? n : st.peek();
            st.push(i); 
        }

        for(int i=0; i<n; i++){ // O(n)
            int currArea = ht[i] * (nse[i]-pse[i]-1);

            maxArea = Math.max(maxArea, currArea);
        }
        return maxArea;
    }
}
// Time Complexity: O(3*n), Space Complexity: O(3*n) (nse, pse, stack storage)

// at each bar of height(ht[i]) - previous smaller element and next smaller element will give the area of rectangle where height will be ht[i] & width will be taken by the difference b/w nse and pse elements.
// maintain a maxArea variable that stores the maximum are throughout the iteration.

// Approach 2 - TOUCH each element
class Solution {
    public int largestRectangleArea(int[] ht) {
        int n = ht.length;
        int maxArea = 0;

        Stack<Integer> st = new Stack<>();

        for(int i=0; i<n; i++){
            while(!st.isEmpty() && ht[st.peek()] >= ht[i]){
                int currElement = st.pop();// touched element //store st.top()
                // st.pop();

                int pse = st.isEmpty() ? -1 : st.peek();
                int nse = i;

                int currArea = ht[currElement] * (nse-pse-1);
                maxArea = Math.max(maxArea, currArea);
            }

            st.push(i);
        }

        // calculate area if stack has elements left in it.
        // WHY? their nse is 'n'; nse = n
        while(!st.isEmpty()){
            int elem = st.pop();
            int nse = n;
            int pse = st.isEmpty() ? -1 : st.peek();

            maxArea = Math.max(maxArea, ht[elem]*(nse-pse-1));
        }
        return maxArea;
    }
}
// Time Complexity: O(n), Space Complexity: O(n) (nse, pse, stack storage)

/* Instead of pre computing (which leads to extra space of nse&pse), 
    - previous smaller element can be computed while traversal itself.
    * How to manage next smaller element?

    an element is TOUCHED, if it's nse and pse both are obtained
        - nse can be found while iteration
        - pse can found be found inside the stack.

Try to Touch all the elements while iteration. If any gets untouched, that means they have nse = n;
Compute maxArea seperately for them.

And,that's it!
*/