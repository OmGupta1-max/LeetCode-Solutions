class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool hasNonZero = false;
        for (int num : nums) {
            totalXor ^= num;

            if (num != 0) {
                hasNonZero = true;
            }
        }
        // Entire array already has non-zero XOR
        if (totalXor != 0) {
            return n;
        }
        // All elements are zero
        if (!hasNonZero) {
            return 0;
        }
        // Total XOR is 0, but at least one element is non-zero.
        // Remove one non-zero element.
        return n - 1;
    }
};