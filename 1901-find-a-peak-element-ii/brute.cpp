// T.C = O(n X m)
// S.C = O(1)

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                int current = mat[i][j];

                int up = -1;
                int down = -1;
                int left = -1;
                int right = -1;

                if (i > 0)
                    up = mat[i - 1][j];

                if (i + 1 < n)
                    down = mat[i + 1][j];

                if (j > 0)
                    left = mat[i][j - 1];

                if (j + 1 < m)
                    right = mat[i][j + 1];

                if (current > up &&
                    current > down &&
                    current > left &&
                    current > right) {

                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};
