class Solution {
public:
    bool winnerSquareGame(int n) {

        // dp[i] = true if the player whose turn it is
        // can force a win with i stones remaining.
        vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; i++) {

            // Try taking every possible perfect square
            for (int j = 1; j * j <= i; j++) {

                // If after taking j*j stones the opponent
                // is in a losing state, current player wins.
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};