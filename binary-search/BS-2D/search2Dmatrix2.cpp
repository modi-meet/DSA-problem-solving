// Search a 2D matix - 2
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Better Solution
class Solution {
    int m, n;
private:
    bool BS(vector<vector<int>>& mat, int target, int row) {
        int st = 0, end = n-1;

        while(st <= end) {
            int mid = (st + end)/2;

            if(mat[row][mid] == target) return true;
            else if(mat[row][mid] > target) end = mid-1;
            else st = mid + 1;
        }

        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        m=mat.size();
        n = mat[0].size();

        int r=0 , c=n-1;
        
        for(int i=0; i<m; i++) {
            if(BS(mat, target, i)) return true;
        }

        return false;
    }
};
// Time Complexity: O(m*logn)

// Optimal Solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(), n = mat[0].size();

        int r=0 , c=n-1;
        
        while(r < m && c >= 0){
            if(target == mat[r][c]){
                return true;
                
            }
            else if(target < mat[r][c]){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
};
// Time Complexity: O(n + m)

// Difference from search in a 2D matix 1, matrix cannot be flatten.