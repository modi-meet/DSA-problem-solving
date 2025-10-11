// Maximum Total Damage With Spell Casting
// Given an array power, where each element represents the damage of a spell.
// It is a known fact that if a magician decides to cast a spell with a damage of power[i], 
// they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2. Each spell can be cast only once.
// Return the maximum possible total damage that a magician can cast.

// Brute Approach
class Solution {
    int n;

private:
    long long solve(int idx, int prev, vector<int>& power){
        if(idx >= n) return 0;

        long long take = 0, notTake = 0;
        if(power[idx] == prev || power[idx] > prev+2) { // take
            take = power[idx] + solve(idx+1, power[idx], power);
        }
        
        // not take
        notTake = solve(idx+1, prev, power);

        return max(take, notTake);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        n = power.size();

        sort(power.begin(), power.end());

        return solve(0, -2, power);
    }
};
// Time Complexity: O(2^n)
// Space Complexity: O(n)

// Recursion + Memoiozed Approach
class Solution {
    int n;
    map<pair<int, int>, int> mp;

private:
    long long solve(int idx, int prev, vector<int>& power){
        if(idx >= n) return 0;
        if(mp.count({idx, prev})) return mp[{idx, prev}];

        long long take = 0, notTake = 0;
        if(power[idx] == prev || power[idx] > prev+2) { // take
            take = power[idx] + solve(idx+1, power[idx], power);
        }
        
        // not take
        notTake = solve(idx+1, prev, power);

        return mp[{idx, prev}] = max(take, notTake);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        n = power.size();

        sort(power.begin(), power.end());

        return solve(0, -2, power);
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
    int n;
    long long t[100001];

private:
    long long solve(int idx, vector<pair<int, int>>& items){
        if(idx >= n) return 0;
        if(t[idx] != -1) return t[idx];

        // take
        long long take = 1LL * items[idx].first * items[idx].second;

        int j = idx+1;
        while (j < n && items[j].first <= items[idx].first + 2) j++;

        take += solve(j, items);
        
        // not take
        long long notTake = solve(idx+1, items);

        return t[idx] = max(take, notTake);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        memset(t, -1, sizeof(t));

        map<int,int> freq;
        for (int p : power) freq[p]++;

        vector<pair<int, int>> items;
        for (auto &p : freq) items.push_back(p);

        n = items.size();

        return solve(0, items);
    }
};


// Most Optimal
typedef long long ll;
class Solution {
    int n;
    unordered_map<ll, ll> freq;
    ll t[100001];

private:
    long long solve(int idx, vector<ll>& nums){
        if(idx >= n) return 0;
        if(t[idx] != -1) return t[idx];

        // take
        int j = lower_bound(nums.begin()+idx+1, nums.end(), nums[idx] + 3) - nums.begin();

        ll take = nums[idx] * freq[nums[idx]] + solve(j, nums);
        
        // not take
        ll notTake = solve(idx+1, nums);

        return t[idx] = max(take, notTake);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        memset(t, -1, sizeof(t));

        for (int p : power) freq[p]++;

        vector<ll> nums;
        for (auto &p : freq) nums.push_back(p.first);

        sort(nums.begin(), nums.end());

        n = nums.size();

        return solve(0, nums);
    }
};
// Time Complexity: O(n log n)
// Space Complexity: O(n)