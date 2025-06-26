// Find Median of two sorted array!

// Brute Force
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> merged(n1+n2);
        int n = merged.size();

        int i1=0, i2=0, i=0;
        while(i1<n1 || i2<n2){
            if(i1<n1 && i2<n2) {
                if(nums1[i1] < nums2[i2]) merged[i] = nums1[i1++];
                else merged[i] = nums2[i2++];
            }
            else if(i1<n1) merged[i] = nums1[i1++];
            else merged[i] = nums2[i2++];

            i++;
        }
        if(n % 2 == 0)
            return (merged[n/2 - 1] + merged[n/2]) / 2.0;
        else
            return merged[n/2];
    }
};
// Time complexity : O(n1+n2)
// Space Complexity : O(n1+n2)

/* EXPLANATION
Brute Force : 
- Intutively create a new sorted array.
- Use two-pointer technique to sort the resultant array in-place.
- return median from the resultant array
*/

// Better
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        int idx2 = n/2, ele2;
        int idx1 = (n/2) - 1, ele1;

        int i1=0, i2=0, i=0;
        while(i1<n1 || i2<n2){
            if(i > idx2) break; // already found the required elements

            if(i1<n1 && i2<n2) {
                if(nums1[i1] < nums2[i2]) {
                    if(i == idx1) ele1 = nums1[i1];
                    if(i == idx2) ele2 = nums1[i1];

                    i1++;
                }
                else {
                    if(i == idx1) ele1 = nums2[i2];
                    if(i == idx2) ele2 = nums2[i2];

                    i2++;
                }
            }
            else if(i1<n1) {
                if(i == idx1) ele1 = nums1[i1];
                if(i == idx2) ele2 = nums1[i1];

                i1++;
            }
            else {
                if(i == idx1) ele1 = nums2[i2];
                if(i == idx2) ele2 = nums2[i2];

                i2++;
            }

            i++;
        }
        if(n % 2 == 0){
            return (ele1+ele2)/2.0;
        }
        else return ele2;
    }
};
// Time complexity : O(n1+n2)
// Space Complexity : O(1)

/* EXPLANATION
Better Approach : 
NOTE : The combination of two-arrays is actually not required.

- how about keeping the track of only indices of the resultant array (combined array in sorted manner)
- as soon as soon as the required index is found,
    - return the median
    - break out of the loop; no further iteration needed.
*/

// OPTIMAL
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1); // make sure nums1 is smaller
        int n = n1+n2;

        int st = 0, end = n1;
        int half = (n+1) / 2;
        while(st <= end){
            int mid1 = (st+end)/2;
            int mid2 = half - mid1; // *

            int r1 = INT_MAX, r2 = INT_MAX;
            int l1 = INT_MIN, l2 = INT_MIN;

            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(mid1-1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2-1 >= 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1){ // find median
                if(n%2 == 0) // combined array is even
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
                else // odd
                    return max(l1, l2);
            }
            else if(l2 > r1) st = mid1+1;
            else end = mid1-1;     
        }
        return 0;       
    }
};
// TIME COMPLEXITY : O(log(N1)) (N1 - size of smaller array)
// Space Complexity : O(1)

/* EXPLANATION
Most Optimal Approach :
NOTE : Since The combination of two-arrays is actually not required, Only keeping the track of indices is enough. 
       - Now, oberve that the resultant array is a combination of two given arrays.
       - It is formed by picking some elements from nums1 and some from nums2.
            - apply binary search on how many elements to take from one array (smallest of two)
       - The median is the middle element of the resultant array.

       - need to divide resultant array into left half & right half, 

- Use Binary Search on the smaller array.
- check whether current partition in the smaller is array is valid or not
    - by comparing resultant array properties
- Partition checks :
    - arr1's last element in the partition(l1) > arr2's first element in the partition(r2)
    - arr2's last element in the partition(l2) > arr1's first element in the partition(r1)
- If partition is valid,
    - resulatant array size,
        odd -> return middle element
        even -> return (middle element - (middle-1)th element) / 2
- typecaste wherever required.

And, that's it!
*/