// Row with Maximum number of 1s
// Given a 2D matrix, return row number that has the maximum number of ones.
// The matrix contains only 0 or 1, rows are sorted.

class Solution {
  public:
    int minRow(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ansRow, ansCnt = 0;

        for(int i=0; i<n; i++) {
            int onesCnt = m - (lower_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin());

            if(onesCnt > ansCnt) {
                ansRow = i;
                ansCnt = onesCnt;
            }
        }        

        return ansRow;
    }
};
// Time Complexity: O(n+logn)