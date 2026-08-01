class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        long long n = nums.size();

        long long actualSum = 0;
        long long actualSqSum = 0;

        for (int num : nums) {
            actualSum += num;
            actualSqSum += 1LL * num * num;
        }

        long long expectedSum = n * (n + 1) / 2;
        long long expectedSqSum = n * (n + 1) * (2 * n + 1) / 6;

        long long sumDiff = expectedSum - actualSum;           // y - x
        long long sqDiff = expectedSqSum - actualSqSum;        // y² - x²

        long long sum = sqDiff / sumDiff;                      // y + x

        long long missing = (sum + sumDiff) / 2;
        long long duplicate = missing - sumDiff;

        return {(int)duplicate, (int)missing};
    }
};