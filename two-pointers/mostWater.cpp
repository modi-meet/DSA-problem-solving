// Container With Most Water

//Brute Force
class Solution {
public:
  int maxArea(vector<int>& height) {
    int n = height.size();
    int max_water = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            max_water = max(max_water, min(height[j], height[i])*(j-i));
        }
    }
    return max_water;
  }
};

// Optimal Approach : Two-pointer
class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0, end = height.size()-1, maxarea=0;

        while(st<end){
            int width = end-st;
            int currentheight = min(height[st], height[end]);
            int currentarea = currentheight * width;

            maxarea = max(maxarea,currentarea);

            if(height[st]<height[end]) st++;
            else end--;
        }
        return maxarea;
    }
};
// Time Complexity : O(N), Space Complexity : O(1)