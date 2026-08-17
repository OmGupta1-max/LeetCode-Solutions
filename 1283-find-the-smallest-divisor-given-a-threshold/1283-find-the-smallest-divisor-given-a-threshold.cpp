class Solution {
public:
    bool possible(vector<int>& nums, int divisor, int threshold) {
        long long sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (possible(nums, mid, threshold))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};