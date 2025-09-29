class Solution {
    int t[51][51];
private:
    int solve(int i, int j, vector<int>& val){
        if (j - i < 2) return 0;

        if(t[i][j] != -1) return t[i][j];

        int ans = INT_MAX;
        for(int k=i+1; k<=j-1; k++){
            int temp = solve(i, k, val) + solve(k, j, val) + val[i]*val[j]*val[k];

            ans = min(ans, temp);
        }
        return t[i][j] = ans;
    }

public:
    int minScoreTriangulation(vector<int>& val) {
        int n = val.size();
        if(n==3) return val[0]*val[1]*val[2];
        memset(t, -1, sizeof(t));

        int i = 0, j = n-1;
        return solve(i, j, val);
    }
};

// convert the given polygon into the form of multiple triangle - triangulate te polygon

// we make cut in such a way that the score is minimum.
// make a cut and solve for the remaining shape. ~ (solve the subproblem)

// there will be n-3 total cuts. 