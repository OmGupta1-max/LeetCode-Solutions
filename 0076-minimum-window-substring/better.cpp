// Time: O(n²)
// Space: O(128) → O(1)

class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(128, 0);

        for (char c : t)
            need[c]++;

        int required = t.size();

        int bestLen = INT_MAX;
        int bestStart = -1;

        for (int left = 0; left < s.size(); left++) {

            vector<int> window(128, 0);
            int formed = 0;

            for (int right = left; right < s.size(); right++) {

                char ch = s[right];
                window[ch]++;

                if (need[ch] > 0 &&
                    window[ch] <= need[ch]) {
                    formed++;
                }

                if (formed == required) {

                    int len = right - left + 1;

                    if (len < bestLen) {
                        bestLen = len;
                        bestStart = left;
                    }
                }
            }
        }

        if (bestStart == -1)
            return "";

        return s.substr(bestStart, bestLen);
    }
};
