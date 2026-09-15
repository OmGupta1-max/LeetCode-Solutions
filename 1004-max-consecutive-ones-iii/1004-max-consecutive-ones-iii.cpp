class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLen = 0;
        
        for (right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeroCount++;
            
            // If we have more than k zeros, shrink the window from the left
            while (zeroCount > k) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }
            
            // Update the maximum window size
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};