// T.C = O(n^2) - Proceed to TLE
// S.C = O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < n; j++) {

                if (nums[i] == nums[j])
                    count++;
            }

            if (count > 1)
                return nums[i];
        }

        return -1;
    }
};
