// Time  = O(n² log(n²)) = O(n² log n)
// Space = O(n²)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        vector<int> arr;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr.push_back(matrix[i][j]);
            }
        }

        sort(arr.begin(), arr.end());

        return arr[k - 1];
    }
};
