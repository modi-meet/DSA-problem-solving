// 3 sum
// Given an integer array,
// return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, j != k and nums[i] + nums[j] + nums[k] == 0.
// (answer should only contain Unique triplets)
// Brute Force
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st; // unique triplets

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if((nums[i]+nums[j]+nums[k]) == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        
                        st.insert(triplet);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
// Time Complexity: O(n^3)
// Space Complexity: O(n) (set)

// Better Approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans_set;

        for(int i=0; i<n; i++){
            set<int> st; 
            for(int j=i+1; j<n; j++){
                int last_num = -(nums[i]+nums[j]);
                
                if(st.count(last_num)){
                    vector<int> triplet = {nums[i], nums[j], last_num};
                    sort(triplet.begin(), triplet.end());
                    ans_set.insert(triplet);
                }    
                st.insert(nums[j]);                
            }
        }
        vector<vector<int>> ans(ans_set.begin(), ans_set.end());
        return ans;
    }
};
// Time Complexity: O(n^2) (n^2*log(m) worse case for set insertion&search)
// Space Complexity: O(n) (set)

/* Explanation:
Similar to brute force, but third loop is replaced with hashing to find the third element.
- 1. fix the first element of the triplet.
- 2. move the second element till end and store the elements visited in a set.
- 3. for each second element, try to find the third element in the set.
    - if found, add sorted triplet to ans(set), eventually to ans vector.
- change the first element to next and repeat for all elements.
*/

// Optimal approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;  
            int j=i+1, k=n-1; 
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    
                    while(j<k && nums[j] == nums[j-1]) j++;
                    // while(j<k && nums[k] == nums[k+1]) k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }
        return ans;
    }
};
// Time Complexity: O(n^2) (n*logn for sorting + n^2 for nested two-pointers)
// Space Complexity : O(1) (ans vector SC is not counted)
/*
Explanation

Hashing was required to find the third element and set was to store unique triplets.
Before storing, sorting of triplet was required.

Sorting the array does not require sorting of triplet. 
- to compute sum:
    - 1. fix the first element of the triplet.
    - 2. use two pointers to find the second and third elements.
        - one pointer starts from the next of first element, and the other from the end of the array.
        - if sum is zero, add triplet to ans vector.
        - if sum is less than zero, move left pointer to right.
        - if sum is greater than zero, move right pointer to left.
    - 3. skip duplicates for the second element. (for third element also, but not necessarily required)

And, that's it!
*/