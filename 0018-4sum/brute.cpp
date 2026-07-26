// T.C = O(n^4) - Proceed to TLE
// S.C = O(number of unique quadruplets)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        set<vector<int>> st;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                for (int k = j + 1; k < n; k++) {

                    for (int l = k + 1; l < n; l++) {

                        long long sum =
                            1LL * nums[i] +
                            nums[j] +
                            nums[k] +
                            nums[l];

                        if (sum == target) {

                            vector<int> temp = {
                                nums[i],
                                nums[j],
                                nums[k],
                                nums[l]
                            };

                            sort(temp.begin(), temp.end());

                            st.insert(temp);
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};
