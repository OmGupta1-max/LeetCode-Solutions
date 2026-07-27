// T.C = O(n^3)
// S.C = O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        int bestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                for (int k = j + 1; k < n; k++) {

                    int sum = nums[i] + nums[j] + nums[k];

                    if (abs(sum - target) < abs(bestSum - target))
                        bestSum = sum;
                }
            }
        }

        return bestSum;
    }
};
