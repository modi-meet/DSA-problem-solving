// Sliding Window Maximum
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. Return the maximums of sliding windows.
class Solution {
public:
    // Whenever you want GREATEST or SMALLEST in O(1) CONSTANT TC, 
    // you should think about MONOTONIC STACK.

    //--------BRUTE FORCE : TC - O(N*K)---------//
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        int maxNum = INT_MIN;

        for(int i=0; i<=n-k; i++){
            int maxNum = INT_MIN;

            for(int j=i; j<i+k; j++){
                maxNum = max(maxNum, nums[j]);
            }

            ans.push_back(maxNum);
        }
        return ans;
    }
};
// Time Complexity: O(N*k), Space Complexity: O(N-k) (ans array)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for(int i=0; i<n; i++){
            // 1. valid window size should be k
            if(!dq.empty() && dq.front() <= i-k){ 
                dq.pop_front();
            }

            // 2. pop all elements that are lesser than current 
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();

            // 3. push the idx of element
            dq.push_back(i);
            
            // 4. if window size is >= k, add current max to ans
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }  

        return ans;
    }
};
// Time Complexity: O(N), Space Complexity: O(K) + O(N-k) (Deque & ans array)


/*
after k elements are already there in the window,
next element comes in and the first element of the window goes out.
- Now, computing maximum element in that k sized window is the main part
- Everytime one elements comes in & the first goes off, seems similart to Queue Data structure.
Now how to maintain maximum elements in queue ?
- that is by maintaining monotonic order
- enter elements in decreasing order! why?
        - as they are in decreasing order, if first goes out the second becomes the next maximum(greater) element.
- And this requires popping out elements that are lesser at back of the queue
- Which can be done via Double Ended Queue(Deque)

* Checks:
1. if window size is more than k, pop from front
2. current element is greater than back of deque(increasing order), pop back form deque
3. push current i
4. if window size is greater than or equal to k, add front of deque (max ele) to ans array.
*/