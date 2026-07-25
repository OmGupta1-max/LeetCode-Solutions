//T.C = O(n^2) = Also TLE in some compiler
//S.C = O(n) - Using Hash Set

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        set<vector<int>> st;

        for (int i = 0; i < n; i++) {

            unordered_set<int> hashset;

            for (int j = i + 1; j < n; j++) {

                int third = -(nums[i] + nums[j]);

                if (hashset.find(third) != hashset.end()) {

                    vector<int> temp = {nums[i], nums[j], third};

                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }

                hashset.insert(nums[j]);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};
