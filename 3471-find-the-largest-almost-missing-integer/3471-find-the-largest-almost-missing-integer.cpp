class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        // Count in how many different windows
        // each number appears.
        unordered_map<int, int> windowCount;
        for (int i = 0; i <= n - k; i++) {
            // Avoid counting the same number twice
            // inside one window.
            unordered_set<int> seen;
            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }
            for (int x : seen) {
                windowCount[x]++;
            }
        }
        int ans = -1;
        // An "almost missing" integer appears
        // in exactly one subarray of length k.
        for (auto &[num, count] : windowCount) {
            if (count == 1) {
                ans = max(ans, num);
            }
        }
        return ans;
    }
};