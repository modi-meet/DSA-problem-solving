// Merge Sorted Array
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int end1 = m-1;
        int end2 = n-1;

        int idx = nums1.length -1;
        while(end1 >=0 && end2 >= 0){
            if(nums1[end1] > nums2[end2]){
                nums1[idx] = nums1[end1];
                end1--;
            } else{
                nums1[idx] = nums2[end2];
                end2--;
            }
            idx--;
        }

        while(end2 >=0 && idx >= 0) nums1[idx--] = nums2[end2--];
    }
}
// Time Complexity: O(m+n), Space Complexity: O(1)

// last while loop is to handle when nums2 has remaining elements but complete nums1 is inserted
 