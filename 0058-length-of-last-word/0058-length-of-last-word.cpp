class Solution {
public:
    int lengthOfLastWord(string s) {
        while (!s.empty() && s.back() == ' ')
            s.pop_back();

        int ans = 0;

        for (int i = s.size() - 1; i >= 0 && s[i] != ' '; i--)
            ans++;

        return ans;
    }
};