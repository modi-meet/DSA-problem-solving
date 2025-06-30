// Longest Harmonious Subsequence
// Approach - 1
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;

        for(int n : nums) mp[n]++;

        auto prev = mp.begin();
        for(int num : nums){
            int minNum = num;
            int maxNum = num+1; // as max allowed diff is 1.

            if(mp.count(num+1)) // maxNUm exist
            ans = max(ans, mp[minNum] + mp[maxNum]);
        }
        return ans;
    }
};
// T.C : O(N), S.C : O(N) (map)

// Approach - 2
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(begin(nums), end(nums));

        int l = 0, r = 1; // r -> *starts from 1

        while(r < n){
            if(nums[r] - nums[l] == 1) ans = max(ans, r-l+1);

            while(nums[r] - nums[l] > 1) l++;

            r++;        
        }

        return ans;
    }
};
// T.C : O(N*logN), S.C : O(1)

/*EXPLANATION
Harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Since maximum allowed difference is 1, The max will be min+1.
- Two pointer / sliding window on sorted array helps finding Longest Harmonious subsequence
Why sorting?
- Sorting helps finding the next non-decreasing character easily.
Count the window length each time when the diff b/w left pointer value and right pointer value is exactly 1.
Note - diff should be exactly 1, so only 1 character subseq is not allowed as diff becomes 0.

Return the longest subseq length.
And, that's it!
*/