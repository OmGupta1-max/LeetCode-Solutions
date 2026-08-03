class Solution {
public:

    vector<int> findPSE(vector<int>& heights) {

        int n = heights.size();
        vector<int> pse(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        return pse;
    }

    vector<int> findNSE(vector<int>& heights) {

        int n = heights.size();
        vector<int> nse(n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> pse = findPSE(heights);
        vector<int> nse = findNSE(heights);

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {

            int width = nse[i] - pse[i] - 1;

            int area = width * heights[i];

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};