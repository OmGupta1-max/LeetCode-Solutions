class Solution {
public:
    int countServers(const vector<vector<int>>& grid) {
        int communicableServersCount = 0;
        vector<int> colCount(size(grid[0]), 0),
            lastServerInRow(size(grid), -1);

        // First pass to count servers in each row and column
        for (int row = 0; row < size(grid); ++row) {
            int serverCountInRow = 0;
            for (int col = 0; col < size(grid[0]); ++col)
                if (grid[row][col]) {
                    serverCountInRow++;
                    colCount[col]++;
                    lastServerInRow[row] = col;
                }
            // If there is more than one server in the row, increase the count
            if (serverCountInRow != 1)
                communicableServersCount += serverCountInRow,
                    lastServerInRow[row] = -1;
        }

        // Second pass to check if servers can communicate
        for (int row = 0; row < size(grid); ++row)
            communicableServersCount += lastServerInRow[row] != -1 &&
                                        colCount[lastServerInRow[row]] > 1;

        return communicableServersCount;
    }
};