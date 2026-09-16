class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        // Step 1: Remove extra spaces
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                // Add space before a new word
                if (index != 0) {
                    s[index++] = ' ';
                }
                // Copy the word
                while (i < n && s[i] != ' ') {
                    s[index++] = s[i++];
                }
            }
        }
        // Resize to remove unused characters
        s.resize(index);
        // Step 2: Reverse entire string
        reverse(s.begin(), s.end());
        // Step 3: Reverse each word
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start,s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};