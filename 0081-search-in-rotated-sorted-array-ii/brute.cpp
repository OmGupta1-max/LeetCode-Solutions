// T.C = O(n)
// S.C = O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        for (int num : nums) {

            if (num == target)
                return true;
        }

        return false;
    }
};
