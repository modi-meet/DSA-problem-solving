class Solution {
    private int LRH(int[] ht){ // Largest rectangle in a hostogram (height array)
        int n = ht.length;
        Stack<Integer> st = new Stack<>();
        int max_area = 0;

        for(int i=0; i<n; i++){
            while(!st.isEmpty() && ht[st.peek()] >= ht[i]) {
                int ele = st.pop();
                int pse = st.isEmpty() ? -1 : st.peek();
                int nse = i;

                int currArea = ht[ele] * (nse-pse-1);
                max_area = Math.max(max_area, currArea);
            }
            st.push(i);
        }
        while(!st.isEmpty()){ // remaining un-TOUCH-ed elements => nse = 'n'
            int ele = st.pop();
            int pse = st.isEmpty() ? -1 : st.peek();
            int nse = n;

            max_area = Math.max(max_area, ht[ele] * (nse-pse-1));
        }

        return max_area;
    }
    
    public int maximalRectangle(char[][] matrix) {
        int r = matrix.length;
        int c = matrix[0].length;
        int maxArea=0;

        int[][] col_sum = new int[r][c]; // prefix 2D array for histogram height

        for(int col=0; col<c; col++){
            int sum = 0;
            for(int row=0; row<r; row++){
                sum += matrix[row][col] - '0';

                if(matrix[row][col] == '0') sum = 0;
                col_sum[row][col] = sum;
            }
        }

        for(int i=0; i<r; i++){ // find maxArea for each row (representing each seperate histogram)
            maxArea = Math.max(maxArea, LRH(col_sum[i]));
        }

        return maxArea;
    }
}
// Time Complexity: O(r*c)
// Space Complexity: O(r*c) + O(c) (col_sum array and stack)