// T.C = O(n X S)
// S.C = O(1)

class Solution {
public:

    bool possible(vector<int>& nums, int maxSum, int k) {
        int subarrays = 1;
        long long currentSum = 0;
        for (int num : nums) {
            if (currentSum + num <= maxSum) {
                currentSum += num;
            }
            else {
                subarrays++;
                currentSum = num;
            }
        }
        return subarrays <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        for (int maxSum = low; maxSum <= high; maxSum++) {
            if (possible(nums, maxSum, k))
                return maxSum;
        }
        return -1;
    }
};
