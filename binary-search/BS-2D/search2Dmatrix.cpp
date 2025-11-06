// Search a 2D Matrix
// Given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

class Solution {
private:
    bool binarySearch(vector<int> & arr,int target){
        int st = 0, end = arr.size()-1;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(target == arr[mid]) return true; 
            else if(target > arr[mid]) st = mid+1;
            else end = mid-1;
        }
            return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row = mat.size(), col = mat[0].size();    

        for(int i=0; i < row; i++){
            if(mat[i][0] <= target && target <= mat[i][col-1]){
                return binarySearch(mat[i], target);
            }
        }
        return false;
    }            
};
// Time Complexity: O(n) + O(logn)

// Optimal Approach

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();    

        int st = 0, end = n*m-1;

        while(st <= end){
            int mid = st + (end-st)/2;

            int r = mid/m, c = mid%m;

            if(mat[r][c] == target) return true; 
            else if(target > mat[r][c]) st = mid+1;
            else end = mid-1;
        }

        return false;
    }            
};
// Time Complexity: O(logn)