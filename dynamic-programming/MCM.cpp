// Matrix Chain Multiplication
// Given an array which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] * arr[i]) for i>=1, find the most efficient way to multiply these matrices together. 
// The efficient way is the one that involves the least number of multiplications.

class Solution {
    int t[102][102];
    
private:
    int solve(int i, int j, vector<int>& arr){
        if(i >= j) return 0;  // 1 size array is also not allowed 
        
        if(t[i][j] != -1) return t[i][j];
        
        int ans = INT_MAX;
        
        for(int k=i; k<=j-1; k++){
            int tempAns = solve(i, k, arr) + solve(k+1, j, arr) + arr[i-1]*arr[k]*arr[j];
            
            ans = min(ans, tempAns);
        }
        
        return t[i][j] = ans;
    }
    
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        memset(t, -1, sizeof(t));

        int i = 1, j = n-1;

        return solve(i, j, arr);
    }
};
// Time ComplexitY: O(n^3)
// Space Complexity: O(n^2)