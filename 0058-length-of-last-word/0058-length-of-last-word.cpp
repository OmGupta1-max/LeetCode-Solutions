class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int curr = 0;

        for (char c : s) {
            if (c == ' ') {
                if (curr > 0) {
                    len = curr;
                    curr = 0;
                }
            } else {
                curr++;
            }
        }

        if (curr > 0)
            len = curr;

        return len;
    }
};