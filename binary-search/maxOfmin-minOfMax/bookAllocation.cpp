// Book Allocation Problem
// Given an array, where arr[i] represents the number of pages in the i-th book. Also have k representing the number of students. 
// The task is to allocate books to each student such that:
// - Each student receives atleast one book.
// - Each student is assigned a contiguous sequence of books.
// - No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student

class Solution {
    int n;
  public:
    bool canWeTake(vector<int> &arr, int k, int limit) {
        int count = 1;
        int cumSum = arr[0];
        
        for(int i=1; i<n; i++){
            if(cumSum + arr[i] > limit) {
                count++;
                cumSum = arr[i]; // reset, new student allocation started 

                if(count > k) return false; // student count exceeded
            }
            else cumSum += arr[i];
        }
        
        return true;
    } 
    
    int findPages(vector<int> &arr, int k) {
        n = arr.size();
        if (k > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(canWeTake(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
                
        }
        return ans;
    }
};
// Time Complexity: O(logm * n)

// minimize the maximum sum