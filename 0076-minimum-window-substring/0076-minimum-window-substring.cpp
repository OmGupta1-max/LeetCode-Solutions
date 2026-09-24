class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);
        // Frequency required from t
        for (char c : t) {
            need[c]++;
        }
        int required = t.size();
        int formed = 0;
        int left = 0;
        int bestLen = INT_MAX;
        int bestStart = -1;
        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            // Add character to window
            window[ch]++;
            // This occurrence satisfies a requirement
            if (need[ch] > 0 && window[ch] <= need[ch]) {
                formed++;
            }
            // Window is valid
            while (formed == required) {
                int len = right - left + 1;
                // Update minimum answer
                if (len < bestLen) {
                    bestLen = len;
                    bestStart = left;
                }
                // Remove left character
                char leftChar = s[left];
                window[leftChar]--;
                // Removing this character broke
                // one required occurrence
                if (need[leftChar] > 0 && window[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }
        }
        if (bestStart == -1)
            return "";
        return s.substr(bestStart, bestLen);
    }
};