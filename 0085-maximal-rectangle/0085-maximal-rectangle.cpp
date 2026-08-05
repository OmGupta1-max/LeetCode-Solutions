class Solution {
public:

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);

        int maxArea = 0;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {

                int height = heights[st.top()];
                st.pop();

                int left;

                if (st.empty())
                    left = -1;
                else
                    left = st.top();

                int width = i - left - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};