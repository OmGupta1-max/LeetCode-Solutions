// Time: O(n² × 128) → effectively O(n²)
// Space: O(128) → O(1)

class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int bestLen = INT_MAX;
        string ans = "";

        vector<int> need(128, 0);

        for (char c : t)
            need[c]++;

        for (int i = 0; i < n; i++) {

            vector<int> window(128, 0);

            for (int j = i; j < n; j++) {

                window[s[j]]++;

                bool valid = true;

                for (int c = 0; c < 128; c++) {
                    if (window[c] < need[c]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    int len = j - i + 1;

                    if (len < bestLen) {
                        bestLen = len;
                        ans = s.substr(i, len);
                    }
                }
            }
        }

        return ans;
    }
};
