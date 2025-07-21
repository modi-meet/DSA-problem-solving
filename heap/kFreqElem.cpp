// Top K Frequent Elements

// Approach #1
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(auto &n : nums) mp[n]++;

        vector<pair<int, int>> vec;
        for(auto& [key, val] : mp){
            vec.push_back({key, val});
        }

        auto lambda = [&](auto p1, auto p2){ // sort based on frequency
            return p1.second > p2.second;
        };

        sort(vec.begin(), vec.end(), lambda);

        vector<int> ans;
        for(int i=0; i<k; i++) ans.push_back(vec[i].first);

        return ans;
    }
};
// Time Complexity: O(n*logn), Space Complelxity: O(n)(map + vector)

// Approach #2
class Solution {
public:
    typedef pair<int, int> P; 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(auto &n : nums) mp[n]++;

        priority_queue<P, vector<P>, greater<P>> pq; // min heap

        // k size heap
        for(auto &[key, val] : mp){
            pq.push({val, key});

            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// Time Complexity: O(n*logK), Space Complelxity: O(n+k) (map + heap)
// after storing frequency in map,
// the problem becomes find k largest elements from map