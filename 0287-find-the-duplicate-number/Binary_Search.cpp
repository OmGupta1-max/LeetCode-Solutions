// T.C = O(nlogn)
// S.C = O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int low = 1;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            int count = 0;

            for (int num : nums) {
                if (num <= mid)
                    count++;
            }

            if (count > mid)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
