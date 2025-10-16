// Peak element 2
// Given a 2D matrix mat where no two adjacent cells are equal, 
// find any peak element and return the array [i,j].

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int top = i-1 < 0 || (mat[i-1][j] < mat[i][j]);
                int bottom = i+1 >= n || (mat[i+1][j] < mat[i][j]);
                int right = j+1 >= m || (mat[i][j+1] < mat[i][j]);
                int left = j-1 < 0 || (mat[i][j-1] < mat[i][j]);

                if(top && bottom && right && left) return {i, j};
            }
        }

        return {};
    }
};
// Time Complexity: O(N*M)

// Optimal
class Solution {
    int n, m;
public:
    int maxEle(int j, vector<vector<int>>& mat){
        int ans = 0;

        for(int i=0; i<n; i++){
            if(mat[i][j] > mat[ans][j]) ans = i;
        }

        return ans;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        int low = 0, high = m-1;

        while(low <= high){
            int mid = (low + high)/2;

            int maxRowIdx = maxEle(mid, mat);

            bool left = (mid == 0) || mat[maxRowIdx][mid] > mat[maxRowIdx][mid - 1];
            bool right = (mid == m - 1) || mat[maxRowIdx][mid] > mat[maxRowIdx][mid + 1];

            if(left && right) return {maxRowIdx, mid};
            else if(mid+1 < m && mat[maxRowIdx][mid + 1] > mat[maxRowIdx][mid]) low = mid + 1;
            else high = mid-1;
        }

        return {};
    }
};
// Time Complexity: O(N*logM)

// We have to go to each element and find the answer
// but n*m is not allowed.
// Hence, we need to skip some elements. 
// Chance of Binary Search algorithm

// Apply binary search on columns