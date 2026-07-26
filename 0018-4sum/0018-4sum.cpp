class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        set<vector<int>> st;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                unordered_set<long long> hashSet;

                for (int k = j + 1; k < n; k++) {

                    long long fourth =
                        1LL * target -
                        nums[i] -
                        nums[j] -
                        nums[k];

                    if (hashSet.find(fourth) != hashSet.end()) {

                        vector<int> temp = {
                            nums[i],
                            nums[j],
                            nums[k],
                            (int)fourth
                        };

                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }

                    hashSet.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};