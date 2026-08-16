class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // count[0] = stones divisible by 3
        // count[1] = stones with remainder 1
        // count[2] = stones with remainder 2
        vector<int> count(3, 0);
        for (int x : stones) {
            count[x % 3]++;
        }
        // Try Alice taking a remainder-1 stone first
        if (canWin(count[0], count[1], count[2]))
            return true;
        // Try Alice taking a remainder-2 stone first
        return canWin(count[0], count[2], count[1]);
    }
private:
    bool canWin(int zero, int one, int two) {
        // Alice must take a non-zero remainder first.
        if (one == 0)
            return false;
        // Alice takes one remainder-1 stone.
        one--;
        // Then players must alternate between remainder 1 and 2.
        int moves = 1 + min(one, two) * 2;
        // If there is an extra remainder-1 stone,
        // one more move can be made.
        if (one > two) {
            one--;
            moves++;
        }
        // The zero-remainder stones don't change the sum modulo 3.
        moves += zero;
        // Alice wins if:
        // 1. The number of moves is odd.
        // 2. Some non-zero-remainder stone is still left.
        return moves % 2 == 1 && one != two;
    }
};