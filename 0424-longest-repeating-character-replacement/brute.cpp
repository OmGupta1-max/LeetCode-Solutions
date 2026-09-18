// T.C = O(n^3)
// S.C = O(26) = O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                vector<int> freq(26, 0);

                for (int x = i; x <= j; x++) {
                    freq[s[x] - 'A']++;
                }

                int maxFreq = 0;

                for (int f : freq) {
                    maxFreq = max(maxFreq, f);
                }

                int len = j - i + 1;

                if (len - maxFreq <= k) {
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};
