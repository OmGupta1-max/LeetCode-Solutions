class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxRow = 0;
            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            int current = mat[maxRow][mid];
            int left = -1;
            if (mid - 1 >= 0) {
                left = mat[maxRow][mid - 1];
            }
            int right = -1;
            if (mid + 1 < m) {
                right = mat[maxRow][mid + 1];
            }
            if (current > left && current > right) {
                return {maxRow, mid};
            }
            if (left > current) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};