//T.C = O(n x m)
//S.C = O(1)

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxNum = *max_element(nums.begin(), nums.end());
        for (int d = 1; d <= maxNum; d++) {
            int sum = 0;
            for (int num : nums) {
                sum += (num + d - 1) / d;
            }
            if (sum <= threshold)
                return d;
        }
        return -1;
    }
};
