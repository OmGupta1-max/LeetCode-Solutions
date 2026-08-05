// T.C = Choose Top        -> O(R)
//Choose Bottom     -> O(R)
//Choose Left       -> O(C)
//Choose Right      -> O(C)
//Check Rectangle   -> O(R × C)
//Total
//O(R³ × C³)''

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxArea = 0;

        for (int top = 0; top < rows; top++) {

            for (int bottom = top; bottom < rows; bottom++) {

                for (int left = 0; left < cols; left++) {

                    for (int right = left; right < cols; right++) {

                        bool valid = true;

                        for (int i = top; i <= bottom && valid; i++) {

                            for (int j = left; j <= right; j++) {

                                if (matrix[i][j] == '0') {
                                    valid = false;
                                    break;
                                }
                            }
                        }

                        if (valid) {

                            int area = (bottom - top + 1) * (right - left + 1);

                            maxArea = max(maxArea, area);
                        }
                    }
                }
            }
        }

        return maxArea;
    }
};
