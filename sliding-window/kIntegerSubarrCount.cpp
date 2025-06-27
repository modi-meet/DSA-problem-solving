// Subarrays with K Different Integers
// BRUTE FORCE
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      int n = nums.size();
      int ans = 0;
      for(int i=0; i<n; i++){
          unordered_map<int, int> freq;
          
          for(int j=i; j<n; j++){
              freq[nums[j]]++;

              if(freq.size() == k) ans++;
              else if(freq.size() > k) break;
          }
      }
      return ans;
    }
};
// TIME COMPLEXITY : O(n^2)
// Space Complexity : O(k)

class Solution {
public:
    int slidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> freq;

        int ans = 0;
        int l=0, r=0;
        while(r<n){
            freq[nums[r]]++;

            while(freq.size() > k){ // more than k distinct elem
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) freq.erase(nums[l]);

                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {        
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};
// TIME COMPLEXITY : O(n)
// Space Complexity : O(k)

/* Since, Count of subarrays with K distinct integers is required:
    - Count no. of subarrays having at most k distinct elem
    - subtract at most k-1
    -> gives the no. of subarrays having exactly k distinct elements

And, that's it!
*/