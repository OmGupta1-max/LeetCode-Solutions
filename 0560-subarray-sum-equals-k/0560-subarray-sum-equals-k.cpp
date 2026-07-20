class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;          // Empty prefix

        int prefix = 0;
        int count = 0;

        for (int num : nums) {

            // Update current prefix sum
            prefix += num;

            // Prefix sum needed to make sum = k
            int need = prefix - k;

            // If found, all occurrences form valid subarrays
            if (mp.find(need) != mp.end()) {
                count += mp[need];
            }

            // Store current prefix sum
            mp[prefix]++;
        }

        return count;
    }
};