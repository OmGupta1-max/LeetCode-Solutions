class Solution {
public:
    bool isValid(string s) {

        bool changed = true;

        while (changed) {

            changed = false;

            size_t pos;

            if ((pos = s.find("()")) != string::npos) {
                s.erase(pos, 2);
                changed = true;
            }

            if ((pos = s.find("[]")) != string::npos) {
                s.erase(pos, 2);
                changed = true;
            }

            if ((pos = s.find("{}")) != string::npos) {
                s.erase(pos, 2);
                changed = true;
            }
        }

        return s.empty();
    }
};