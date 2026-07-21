class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        // Generate every row
        for (int row = 0; row < numRows; row++) {

            vector<int> current;

            // First element is always 1
            current.push_back(1);

            // Fill middle elements
            if (row > 0) {

                vector<int>& previous = ans[row - 1];

                for (int i = 0; i < previous.size() - 1; i++) {
                    current.push_back(previous[i] + previous[i + 1]);
                }

                // Last element is always 1
                current.push_back(1);
            }

            // Store current row
            ans.push_back(current);
        }

        return ans;
    }
};