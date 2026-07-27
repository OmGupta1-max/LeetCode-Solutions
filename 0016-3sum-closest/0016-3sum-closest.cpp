class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int bestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // Update the closest sum
                if (abs(sum - target) < abs(bestSum - target))
                    bestSum = sum;

                // Exact answer found
                if (sum == target)
                    return sum;

                // Need a larger sum
                else if (sum < target)
                    left++;

                // Need a smaller sum
                else
                    right--;
            }
        }

        return bestSum;
    }
};