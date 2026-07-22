class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        for(int num : nums)
        {
            // No candidate currently
            if(count == 0)
            {
                candidate = num;
            }

            // Vote for candidate
            if(num == candidate)
            {
                count++;
            }
            // Cancel one vote
            else
            {
                count--;
            }
        }

        return candidate;
    }
};