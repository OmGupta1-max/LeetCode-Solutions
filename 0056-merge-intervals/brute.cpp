//T.C = O(n²) (In practice, repeated merging can make it even worse.)
//S.C = O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<bool> visited(n, false);
        vector<vector<int>> ans;

        bool merged = true;

        while (merged) {

            merged = false;
            visited.assign(n, false);
            ans.clear();

            for (int i = 0; i < n; i++) {

                if (visited[i])
                    continue;

                int start = intervals[i][0];
                int end = intervals[i][1];

                visited[i] = true;

                for (int j = i + 1; j < n; j++) {

                    if (!visited[j] &&
                        !(intervals[j][0] > end || intervals[j][1] < start)) {

                        start = min(start, intervals[j][0]);
                        end = max(end, intervals[j][1]);

                        visited[j] = true;
                        merged = true;
                    }
                }

                ans.push_back({start, end});
            }

            intervals = ans;
            n = intervals.size();
        }

        return intervals;
    }
};
