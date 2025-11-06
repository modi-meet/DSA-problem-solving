// Median in a row-wise sorted Matrix
// Given a row-wise sorted matrix, where the number of rows and columns is always odd. 
// Return the median of the matrix.

class Solution {
    int n, m;
private:
    int countSmallEqual(vector<vector<int>> &mat, int val) {
        int cnt = 0;
        
        for(int i=0; i<n; i++) {
            cnt += upper_bound(mat[i].begin(), mat[i].end(), val) - mat[i].begin();
        }
        
        return cnt;
    }
    
public:
    int median(vector<vector<int>> &mat) {
        n = mat.size();
        m = mat[0].size();
        
        int st = INT_MAX; // points smallest element in the matrix 
        for(int i=0; i<n; i++) {
            st = min(st, mat[i][0]);
        }
        
        int end = INT_MIN; // points largest element in the matrix 
        for(int i=0; i<n; i++) {
            end = max(end, mat[i][m-1]);
        }
        
        int req = n * m / 2; // req no. of elements that need to be there to the left of median elem
        
        while(st <= end) {
            int mid = st + (end-st) / 2;
            
            int smallerEq = countSmallEqual(mat, mid);
        
            if(smallerEq <= req) st = mid + 1;
            else end = mid - 1;
        }
    
        return st;
    }
};
// Time Complexity: O(n*logM * 10^9)
