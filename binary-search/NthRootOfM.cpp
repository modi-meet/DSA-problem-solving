// Find nth root of m
// If the root is not integer then returns -1.

class Solution {
  public:
    int nthRoot(int n, int m) {
        int low = 1, high = m;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(pow(mid, n) == m) return mid;
            else if(pow(mid, n) > m) high = mid-1;
            else low = mid+1;
        }

        return -1;
    }
};
// Time Complexity: O(n * logm)

// alternate apporach
class Solution {
  public:
    long long powerFunc(int num, int power, int OriginalNum){
        long long result = 1;
        for (int i = 0; i < power; i++) {
            result *= num;
            
            if (result > OriginalNum) return OriginalNum + 1; // early stop if exceeds
        }
        return result;
    }
    
    int nthRoot(int n, int m) {
        int low = 1, high = m;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            long long val = powerFunc(mid, n, m);
            
            if(val == m) return mid;
            else if(val > m) high = mid-1;
            else low = mid+1;
        }

        return -1;
    }
};
// Time Complexity: O(n * logm)

// Optimized approach
class Solution {
  public:
    long long powerFunc(int num, int power, int OriginalNum){
        long long ans = 1;
        
        while(power > 0){
            if(power % 2 == 1) {
                ans *= num;
                
                if(ans > OriginalNum) return OriginalNum+1;
            }
            
            power /= 2;
            if(power > 0){
                num *= num;
                
                if(num > OriginalNum) return OriginalNum+1;
            }
        }
        
        return ans;
    }
    
    int nthRoot(int n, int m) {
        int low = 1, high = m;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            long long val = powerFunc(mid, n, m);
            
            if(val == m) return mid;
            else if(val > m) high = mid-1;
            else low = mid+1;
        }

        return -1;
    }
};
// Time Complexity: O(log n * log m)