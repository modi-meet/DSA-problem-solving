// Partitions with Given Difference
// Given an array and a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

class Solution {
    int n;
    int t[52][176];
    
    int countSubsetSum(vector<int>& arr, int target, int idx) {
        if(target < 0) return 0;
        
        if(idx >= n){
            if(target == 0) return 1;
            
            return 0;
        }
        
        if(t[idx][target] != -1) return t[idx][target];
        
        int take = 0;
        if(arr[idx] <= target) 
            take = countSubsetSum(arr, target-arr[idx], idx+1);
        
        int notTake = countSubsetSum(arr, target, idx+1);
        
        return t[idx][target] = take+notTake;
    }
    
  public:
    int countPartitions(vector<int>& arr, int d) {
        n = arr.size();
        
        int totalSum = 0;
        for(int num : arr) totalSum += num;
        
        int sum = (d + totalSum)/2;
        
        if ((d + totalSum) % 2 != 0) return 0; // not possible
        
        memset(t, -1, sizeof(t));

        return countSubsetSum(arr, sum, 0);
    }
};
// Time Complexity: O(n*target)
// Space Complexity: O(n*target)