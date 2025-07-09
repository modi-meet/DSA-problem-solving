// Asteroids Collision
// given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
// If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int n = asteroids.length;
        Stack<Integer> st = new Stack<>();

        for(int i=0; i<n; i++){
            if(asteroids[i] < 0){
                while(!st.isEmpty() && st.peek() > 0 && Math.abs(asteroids[i]) > st.peek()){
                    st.pop(); // pop till current asteroid is greater than previous ones 
                }

                if(!st.isEmpty() && Math.abs(asteroids[i]) == st.peek()) st.pop(); // both explodes
                else if(st.isEmpty() || st.peek() < 0) st.push(asteroids[i]); // add -ve element to stack
            } else st.push(asteroids[i]);
        }
        
        int[] ans = new int[st.size()];
        for(int i=ans.length-1; i>=0; i--) ans[i] = st.pop();

        return ans;
    }
}
// Time Complexity: O(2*n), O(n)