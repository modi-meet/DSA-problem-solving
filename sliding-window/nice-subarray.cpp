// Count Nice Subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int> nums, int k) {
        int n = nums.size();

        int totalNice = 0;
        for(int i=0; i<n; i++){
            int odd = 0, cnt = 0;

            for(int j=i; j<n; j++){
                if(nums[j] % 2 != 0) odd++;
                if(odd == k) {
                    cnt++;
                } else if(odd > k) break;
            }
            totalNice += cnt;
        }
        return totalNice;
    }
};

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;

        // unordered_map<int, int> m;
        // m.insert({0,1});

        // int primes = 0;

        // for(int i=0; i<n; i++){   
        //     primes += (nums[i]%2);
                
        //     if(m.count(primes - k)){
        //         ans += m[primes-k];
        //     }

        //     m[primes]++;
        // }

        int r=0, l=0;
        int odd=0, prevCount =0 ;
        //prevCount- How many valid subarrays end at r and have exactly k odd numbers

        while(r<n){
            if(nums[r]%2 != 0){ //odd
                odd++;
                prevCount = 0;
            }

            while(odd == k){
                prevCount++;

                if(l<n && nums[l]%2 == 1) odd--; //odd

                l++;
            }

            ans += prevCount;
            r++;            
        }
        return ans;
    }
};