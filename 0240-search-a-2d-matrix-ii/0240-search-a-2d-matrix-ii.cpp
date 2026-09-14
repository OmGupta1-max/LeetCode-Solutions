class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // Start from top-right corner
        int row = 0;
        int col = m - 1;
        while (row < n && col >= 0) {
            int current = matrix[row][col];
            // Target found
            if (current == target) {
                return true;
            }
            // Current is too large
            // Move left
            else if (current > target) {
                col--;
            }
            // Current is too small
            // Move down
            else {
                row++;
            }
        }
        return false;
    }
};