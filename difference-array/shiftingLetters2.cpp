// Shifting Letters 2
// Given a string s and a 2D array shifts where shifts[i] = [start_i, end_i, direction_i]. 
// For every i, 
// shift the characters in s from the index start_i to end_i
// - forward if direction_i = 1, or
// - backward if direction_i = 0.
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n , 0); // Difference array
        
        // Step 1: create the difference array
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) { 
                diff[start] += 1;
                if(end+1 < n) diff[end + 1] -= 1;
            } 
            else { 
                diff[start] -= 1;
                if(end+1 < n) diff[end + 1] += 1;
            }
        }
        
        // Step 2: Compute the prefix sum to get the net-shifts for each character
        vector<int> cumSum(n, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += diff[i];
            cumSum[i] = sum; // Add the value from the previous index
        }
        
        // Step 3: Apply the shifts to the string
        for (int i = 0; i < n; ++i) {
            int shift = cumSum[i]; // Ensure shift is within the range [0, 25]

            if (shift < 0)
                shift += 26; // Handle negative shifts (backward)
            
            // Apply the shift to character
            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
            
        }
        
        return s;
    }
};// Time Complexity: O(N+M)
// Space Complexity: O(N) (diff array and cumSum array)

/*
Note : s[i]-'a' gives the corresponding number of character s[i]
        +shift  adds the shift
        %26     is to wrap around (0-25)
        + 'a'   in the end, converts back the number to character
*/