/*
class Solution {
    int t[102][10002];
private:
    int solve(int e, int f){
        if(e == 1) return f;
        if(f == 0 || f == 1) return f;
        
        if(t[e][f] != -1) return t[e][f];
        
        int ans = INT_MAX;
        for(int k=1; k<=f; k++){
            int temp = max(solve(e-1, k-1), solve(e, f-k)) + 1; // +1 for attempt
            
            ans = min(ans, temp);
        }
        
        return t[e][f] = ans;
    }
    
public:
    int superEggDrop(int e, int f) { // egg, floor
        if(e == 1) return f;
        
        memset(t, -1, sizeof(t));
        
        return solve(e, f);
    }
};
// Time Complexity: O((n^2) * k)
// Space Complexity: O(k * n)
*/

class Solution {
    int t[102][10002];
private:
    int solve(int e, int f){
        if(e == 1) return f;
        if(f == 0 || f == 1) return f;
        
        if(t[e][f] != -1) return t[e][f];

        int st = 1, end = f;
        
        int ans = INT_MAX;
        while(st <= end){
            int mid = st + (end - st)/2;

            int low = solve(e-1, mid-1);
            int up = solve(e, f-mid);

            int temp = 1 + max(low, up);
            
            if(low < up) st = mid+1;
            else end = mid - 1;

            ans = min(ans, temp);
        }
        
        return t[e][f] = ans;
    }
    
public:
    int superEggDrop(int e, int f) { // egg, floor
        if(e == 1) return f;
        
        memset(t, -1, sizeof(t));
        
        return solve(e, f);
    }
};
// Time Complexity: O((n * k) * logn)
// Space Complexity: O(n * k)