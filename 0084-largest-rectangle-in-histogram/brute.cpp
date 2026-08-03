// T.C = O(n²) - Proceed to TLE
// S.C = O(1)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        int maxArea = 0;

        for (int left = 0; left < n; left++) {

            int minHeight = INT_MAX;

            for (int right = left; right < n; right++) {

                minHeight = min(minHeight, heights[right]);

                int width = right - left + 1;

                int area = width * minHeight;

                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
