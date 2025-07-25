// Given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].
// Each queries[i] represents the following action on nums:
// - Decrement the value at each index in the range [li, ri] in nums by at most vali.
// - The amount by which each value is decremented can be chosen independently for each index.
// Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array.
// If no such k exists, return -1.
class Solution {
    int n, q;

    bool diffArrTech(vector<int>& nums, vector<vector<int>>& queries, int k){
        vector<int> diff(n, 0);

        for(int i=0; i<=k; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;
            if(r+1 < n) diff[r+1] -= x;
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += diff[i];
            diff[i] = sum;

            if(nums[i] > diff[i]){ // could not make it zero
                return 0;
            }
        }
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        q = queries.size();

        auto lambda = [](auto x) {
            return x == 0; 
        };

        if(all_of(nums.begin(), nums.end(), lambda)) return 0; // already a ZeroArray

        // for(int i=0; i<q; i++){ // O(q * (q+n))
        //     if(diffArrTech(nums, queries, i) == true)
        //         return i+1; // return k
        // }

        int k = -1;

        int l=0, r=q-1; // Binary search on queries
        while(l <= r){
            int mid = l+(r-l)/2;

            if(diffArrTech(nums, queries, mid) == true) {
                k = mid+1;
                r = mid-1; // check for lesser k now
            } else {
                l = mid+1; // increase the k
            }
        }

        return k;
    }
};
// Linearly -> Time Comlexity:  O(q * (q+n))
// Binary Search -> Time Comlexity:  O(log(q) * (q+n))