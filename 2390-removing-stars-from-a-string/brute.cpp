// T.C = O(n^2)
// S.C = O(1)

class Solution {
public:
    string removeStars(string s) {

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '*') {

                int j = i - 1;

                while (j >= 0 && s[j] == '*')
                    j--;

                if (j >= 0) {
                    s.erase(j, 1);

                    i--;  // '*' shifted left
                }

                s.erase(i, 1);

                i--;
            }
        }

        return s;
    }
};
