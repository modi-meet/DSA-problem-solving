class Solution {
public:
    int maxBanana(vector<int>& piles){
        int ans=INT_MIN;

        for(int i=0; i<piles.size();i++){
            ans = max(ans, piles[i]);
        }
        return ans;
    }

    long long calculateTime(vector<int>&piles, int speed){
        long long TotalHour = 0;

        for(int i=0; i<piles.size(); i++){
            TotalHour += (piles[i] + speed - 1)/speed;
        }
        return TotalHour;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high = maxBanana(piles);

        while(low <= high){
            int mid = low + (high - low)/2;
            long long timeReq = calculateTime(piles, mid);

            if(timeReq <= h){
                high=mid-1; //check for lower speed
            } else 
                low=mid+1;  //check for higher speed
        }
        return low;
     }
};
// Time Complexity: O(log n * log(mxElem) )

// if we eat mid bananas, how musch time will it take to complete all
// If greater than allowed(h), increase bananas,
// else try to reduce bananas, since we need the minimum