class Solution {
public:
    int minimumPushes(string word) {
        int pushes = 0;
        for (int i = 0; i < word.size(); i++) {
// Every 8 characters increase the number of pushes
            pushes+=(i / 8)+1;
        }
        return pushes;
    }
};