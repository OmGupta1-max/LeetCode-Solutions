// Time  = O(k log n)
// Space = O(n)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        // {value, row, column}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // Put first element of every row
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int answer = 0;

        for (int count = 0; count < k; count++) {

            auto [value, row, col] = pq.top();
            pq.pop();

            answer = value;

            // Add next element from same row
            if (col + 1 < n) {
                pq.push({
                    matrix[row][col + 1],
                    row,
                    col + 1
                });
            }
        }

        return answer;
    }
};
