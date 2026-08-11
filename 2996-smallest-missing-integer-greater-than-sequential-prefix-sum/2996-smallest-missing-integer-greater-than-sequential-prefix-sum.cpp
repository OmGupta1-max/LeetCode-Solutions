class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int prefixSum = nums[0];

        // Find sequential prefix sum
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1] + 1)
            {
                prefixSum += nums[i];
            }
            else
            {
                break;
            }
        }

        // Store all elements
        unordered_set<int> st;

        for(int num : nums)
        {
            st.insert(num);
        }

        // Find smallest missing integer >= prefixSum
        while(st.count(prefixSum))
        {
            prefixSum++;
        }

        return prefixSum;
    }
};