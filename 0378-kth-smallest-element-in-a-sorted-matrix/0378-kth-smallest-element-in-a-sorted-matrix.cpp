class Solution {
public:

    // Count how many elements are <= mid
    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int row = n - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                // Everything above this element
                // in this column is also <= mid
                count += row + 1;
                col++;
            }
            else {
                // Current element is too large
                // Move upward
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        // Binary search on value
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid);
            if (count >= k) {
                // kth element can be mid or smaller
                high = mid;
            }
            else {
                // kth element must be greater
                low = mid + 1;
            }
        }
        return low;
    }
};