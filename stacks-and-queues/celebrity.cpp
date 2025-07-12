// The Celebrity Problem
// A celebrity is a person who is known to all but does not know anyone at a party.
// A square matrix mat[][] (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person.
// Return the index of the celebrity in the party, if the celebrity does not exist, return -1.

// Approach: 1
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        
        vector<int> knowMe(n, 0); // person known by how many other people
        vector<int> iKnow(n, 0); // person knows how many other people at party
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                
                if(mat[i][j] == 1){
                    knowMe[j]++; // j is known by i
                    iKnow[i]++; // i is known by j
                }
            }
        }

        for(int i=0; i<n; i++){
            if(knowMe[i] == n-1 && iKnow[i] == 0) return i;
        }
        
        return -1;
    }
};
// Time Complxity: O(n^2), Space Complexity: O(2*n)

// Approach: 2
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        
        int top = 0, bottom = n-1;
        
        while(top < bottom){
            if(mat[top][bottom] == 1) top++; // top knows bottom
            else if(mat[bottom][top] == 1) bottom--; // bottom knows top
            else {top++; bottom--;} // both doesn't know each other; not a celebrity
        }
        
        if(top > bottom) return -1;
        
        for(int i=0; i<n; i++){
            if(i == top) continue;
            
            if(!(mat[top][i] == 0 && mat[i][top] == 1)) return -1;
        }
        
        return top;
    }
};
// Time Complxity: O(n), Space Complexity: O(1)