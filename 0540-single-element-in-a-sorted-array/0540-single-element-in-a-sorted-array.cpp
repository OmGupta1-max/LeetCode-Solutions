class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // Make mid even
            if (mid % 2 == 1)
                mid--;

            // Correct pair found
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            }
            // Pair is broken
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};