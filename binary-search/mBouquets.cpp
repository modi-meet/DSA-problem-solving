// Minimum Days to Make m Bouquets
// Make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

class Solution {
    int n;
public:
    bool areMbouqPossible(vector<int>& bloomDay, int m, int k, int day){
        int total = 0, count = 0;

        for(int i=0; i<n; i++){
            if(bloomDay[i] <= day) count++;
            else count = 0;

            if(count >= k) {
                total++;
                count = 0;
            }

            if(total >= m) return true;
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        n = bloomDay.size();
        if(1LL * m * k > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(areMbouqPossible(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;  // find lesser value of day
            }
            else low = mid+1;            
        }

        return ans;
    }
};
// Time Complexity: O(n * log(max bloomDay) )

// m bouquets of size k