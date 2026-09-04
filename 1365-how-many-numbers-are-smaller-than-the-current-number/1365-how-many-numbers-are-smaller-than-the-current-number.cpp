class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        // Frequency
        for (int num : nums) {
            count[num]++;
        }
        // Prefix sum
        for (int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }
        vector<int> ans;
        for (int num : nums) {
            if (num == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(count[num - 1]);
            }
        }
        return ans;
    }
};