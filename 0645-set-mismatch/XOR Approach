// T.C = O(n)
// S.C = O(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();

        int xr = 0;

        // XOR of array and numbers 1..n
        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        // Rightmost set bit
        int bit = xr & (-xr);

        int bucket1 = 0;
        int bucket2 = 0;

        // Divide array into two groups
        for (int num : nums) {
            if (num & bit)
                bucket1 ^= num;
            else
                bucket2 ^= num;
        }

        // Divide numbers 1..n into two groups
        for (int i = 1; i <= n; i++) {
            if (i & bit)
                bucket1 ^= i;
            else
                bucket2 ^= i;
        }

        // Identify duplicate and missing
        for (int num : nums) {
            if (num == bucket1)
                return {bucket1, bucket2};
        }

        return {bucket2, bucket1};
    }
};
