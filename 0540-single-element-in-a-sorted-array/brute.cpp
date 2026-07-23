// Using HashMap (unordered_map)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        unordered_map<int, int> freq;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Find element with frequency 1
        for (auto it : freq) {
            if (it.second == 1)
                return it.first;
        }

        return -1;
    }
};
