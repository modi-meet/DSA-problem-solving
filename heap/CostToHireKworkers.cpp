// Total Cost to Hire K Workers
class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int c) { // c - candidates
        int n = cost.size();
        long long total_cost = 0;
        int l = 0, r = n-1;

        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        while(k > 0){
            while(pq1.size() < c && l<=r){
                pq1.push(cost[l]); l++;
            }

            while(pq2.size() < c && r>=l){
                pq2.push(cost[r]); r--;
            }

            int cost1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int cost2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if(cost1 <= cost2) {
                total_cost += cost1;
                pq1.pop();
            } else {
                total_cost += cost2;
                pq2.pop();
            }

            k--;
        }

        return total_cost;
    }
};
// Time Complexity: O(k * log(c)) (k rounds * heap insertion and pop)
// Space Complexity: O(c)  

// We need to hire k worders
// In each round, only c candidates from front and c from last can sit. Only one candidate is selected in one round. 
// hence k rounds are performed.
// hire the worker who has the least cost.
// A worker can be chosen only once.
// Break the tie by selecting least index.