// Trap Rain Water
// Compute how much water can be trapped after raining given an array of heights of bars.

// Brute Force Approach
class Solution {
    public int trap(int[] ht) {
        int n = ht.length;
        int[] store = new int[n];
        int water = 0;

        for(int i=0; i<n; i++){ // i=0 -> n
            int leftMax = 0, rightMax = 0;
            for(int l=i-1; l>=0; l--){ // 0 <- i-1 
                leftMax = Math.max(leftMax, ht[l]);
            }

            for(int r=i+1; r<n; r++){ // i+1 -> n
                rightMax = Math.max(rightMax, ht[r]);
            } 

            int currWater = Math.min(leftMax, rightMax) - ht[i];
            store[i] = currWater;
        }

        for(int i=0; i<n; i++){
            if(store[i] > 0) water += store[i];
        }
        return water;
    }
}
// Time Complexity: O(n^2), Space Complexity: O(n)
// water stored st each bar = min(leftMax, rightMax)-height[i]

// Better Approach
class Solution {
    public int trap(int[] ht) {
        int n = ht.length;
        int[] preMax = new int[n];
        int[] suffMax = new int[n];
        int water = 0;

        preMax[0] = ht[0];
        for(int i=1; i<n; i++){
            preMax[i] = Math.max(preMax[i-1], ht[i]);
        }

        suffMax[n-1] = ht[n-1];
        for(int i=n-2; i>=0; i--){
            suffMax[i] = Math.max(suffMax[i+1], ht[i]);
        }

        for(int i=0; i<n; i++){ // i=0 -> n
            int leftMax = preMax[i], rightMax = suffMax[i];

            if(ht[i] < leftMax && ht[i] < rightMax)
                water += Math.min(leftMax, rightMax) - ht[i];
        }
        return water;
    }
}
// Time Complexity: O(3*n), Space Complexity: O(2*n)

// Optimal Solution
class Solution {
    public int trap(int[] ht) {
        int n = ht.length;
        int water = 0;
        int lmax = 0, rmax = 0;

        int l = 0, r = n-1;
        while(l<r){
            lmax = Math.max(lmax, ht[l]);
            rmax = Math.max(rmax, ht[r]);

            if(lmax < rmax){
                water += lmax - ht[l];
                l++;
            } else {
                water += rmax - ht[r];
                r--;
            }
        }
        return water;
    }
}
// Time Complexity: O(n), Space Complexity: O(1)

// NOTE : Only lesser height bar contributes to water storage, so water collected at each bar will be (minimum bar - curr height).
/* WHY TWO-POINTERS WORKS?
- moving minimum height pointer ensures maximum possible water that can be trapped, has been calculated.
- And, moving lesser pointer directly suggest that go for bigger bar to store more water if any.
*/