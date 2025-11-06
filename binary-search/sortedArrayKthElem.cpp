// K-th element of two Arrays
// Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        if(n1 > n2) return kthElement(b, a, k);
        
        int n = n1+n2;
        int half = k; // no. of elements in left part
        
        int low = max(0, k-n2), high = min(k, n1);
        
        while(low <= high) {
            int mid1 = low + (high-low)/2;
            int mid2 = half - mid1;

            int r1 = INT_MAX, r2 = INT_MAX;
            int l1 = INT_MIN, l2 = INT_MIN;

            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];

            if(mid1-1 >= 0) l1 = a[mid1 - 1];
            if(mid2-1 >= 0) l2 = b[mid2 - 1];

            if(l1 <= r2 && l2 <= r1){ // find median
                return max(l1, l2);
            } 
            else if(l1 > r2) high = mid1-1;
            else low = mid1+1;
        }
        
        return 0;
    }
};
// TIME COMPLEXITY : O(log(N1)) (N1 - size of smaller array)
// Space Complexity : O(1)