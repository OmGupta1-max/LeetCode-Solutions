class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int first = 0;
        int second = 0;

        for (int num : nums) {

            // Update largest
            if (num > first) {
                second = first;
                first = num;
            }

            // Update second largest
            else if (num > second) {
                second = num;
            }
        }

        return (first - 1) * (second - 1);
    }
};