// Time = O(n)
// Space = O(n)

class Solution {
public:
    string reverseWords(string s) {
        // Remove extra spaces
        string temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                temp += s[i];
            }
            else if (!temp.empty() && temp.back() != ' ') {
                temp += ' ';
            }
        }
        // Remove trailing space
        if (!temp.empty() && temp.back() == ' ') {
            temp.pop_back();
        }
        // Reverse entire string
        reverse(temp.begin(), temp.end());
        // Reverse each word
        int start = 0;
        for (int i = 0; i <= temp.size(); i++) {
            if (i == temp.size() || temp[i] == ' ') {
                reverse(temp.begin() + start,temp.begin() + i);
                start = i + 1;
            }
        }
        return temp;
    }
};
