// Kth Largest Element in an Array

// Brute Approach
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        sort(rbegin(nums), rend(nums)); // decreasing order sorting
        return nums[k-1];
    }
};
// Time Complexity: O(Nlogk)
// Space Complexity: O(1)

// Approach-2 : Using Min Heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i=0; i<n; i++){
            min_heap.push(nums[i]);

            if(min_heap.size() > k) min_heap.pop();
        }

        return min_heap.top();
    }
};
// Time Complexity: O(Nlogk)
// Space Complexity: O(k)

//------------- Alternate Question Format ----------------//
/*
Implement the KthLargest class:
- KthLargest(int k, int[] nums) - Initializes the object with the integer k and the array of test scores nums.
- int add(int val) - Adds a new test score val to the stream and returns the element representing the kth largest element in the array of test scores so far.
*/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k_;

    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        
        for(int i=0; i<nums.size(); i++){
            min_heap.push(nums[i]);

            if(min_heap.size() > k_) min_heap.pop();
        }
    }
    
    int add(int val) {
        min_heap.push(val);

        if(min_heap.size() > k_) min_heap.pop();

        return min_heap.top();    
    }
};
