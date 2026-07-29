// T.C = O(n^2)
// S.C = O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();

        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int width = j - i;

                int h = min(height[i], height[j]);

                int area = width * h;

                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
