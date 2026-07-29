class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();

        int duplicate = -1;
        int missing = -1;

        for (int num = 1; num <= n; num++) {

            int count = 0;

            for (int i = 0; i < n; i++) {

                if (nums[i] == num)
                    count++;
            }

            if (count == 2)
                duplicate = num;

            if (count == 0)
                missing = num;
        }

        return {duplicate, missing};
    }
};