class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            // Add current character
            freq[s[right] - 'A']++;
            // Update maximum frequency
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            // Shrink if window is invalid
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            // Update answer
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};