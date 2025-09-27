//  Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
// given a boolean expression s containing
//     'T' ---> true
//     'F' ---> false 
// and following operators between symbols
//    &   ---> boolean AND
//     |   ---> boolean OR
//    ^   ---> boolean XOR

class Solution {
    int t[102][102][2];
    
private:
    int solve(string& s, int i, int j, bool isTrue){
        if(i > j) return 0;
        
        if(i == j){
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if(t[i][j][isTrue] != -1) return t[i][j][isTrue];
        
        int ans = 0;
        for(int k=i+1; k<=j-1; k += 2){
            // temp
            int lT = solve(s, i, k-1, true);
            int lF = solve(s, i, k-1, false);
            int rT = solve(s, k+1, j, true);
            int rF = solve(s, k+1, j, false);
            
            // updating ans
            if(s[k] == '&'){
                if(isTrue) ans += lT * rT;
                else ans += lF*rF + lF*rT + lT*rF;
            }
            else if(s[k] == '|'){
                if(isTrue) ans += lT*rT + lT*rF + lF*rT;
                else ans += lF * rF;
            }
            else { // XOR '^'
                if(isTrue) ans += lT*rF + lF*rT;
                else ans += lT*rT + lF*rF;
            }
            
        }
        
        return t[i][j][isTrue] = ans;
    }

public:
    int countWays(string &s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        
        int i = 0, j = n-1;
        
        return solve(s, i, j, true);
    }
};

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

// Map can be used to store the dp instead of 3D matrix.