class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        string middle = "";

        // Build the left half in lexicographical order
        for (int i = 0; i < 26; i++) {

            left.append(freq[i] / 2, char('a' + i));

            // Character with odd frequency goes in the middle
            if (freq[i] % 2 == 1) {
                middle = char('a' + i);
            }
        }

        // Right half is reverse of left half
        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};