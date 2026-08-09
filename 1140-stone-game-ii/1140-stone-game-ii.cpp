class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix[i] = total stones from i to the end
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M] = maximum stones current player can get
        // starting from i with current M
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {

            for (int M = 1; M <= n; M++) {

                // If we can take all remaining piles
                if (2 * M >= n - i) {
                    dp[i][M] = suffix[i];
                    continue;
                }

                // Try taking X piles, where 1 <= X <= 2*M
                for (int X = 1; X <= 2 * M && i + X <= n; X++) {

                    // Opponent gets dp[i + X][max(M, X)]
                    // So we get the remaining stones minus that.
                    dp[i][M] = max(
                        dp[i][M],
                        suffix[i] - dp[i + X][max(M, X)]
                    );
                }
            }
        }

        return dp[0][1];
    }
};