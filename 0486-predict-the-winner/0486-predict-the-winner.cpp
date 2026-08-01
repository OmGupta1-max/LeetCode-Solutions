class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n));

        // Base case
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        // Fill DP table
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                int pickLeft = nums[i] - dp[i + 1][j];

                int pickRight = nums[j] - dp[i][j - 1];

                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};