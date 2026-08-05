class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);

        // Build graph
        for (auto &edge : invocations) {
            graph[edge[0]].push_back(edge[1]);
        }

        // Find all suspicious methods
        vector<bool> suspicious(n, false);

        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int next : graph[node]) {

                if (!suspicious[next]) {
                    suspicious[next] = true;
                    q.push(next);
                }
            }
        }

        // If any non-suspicious method calls a suspicious one,
        // we cannot remove them.
        for (auto &edge : invocations) {

            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v]) {

                vector<int> ans;

                for (int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }

        // Return remaining (non-suspicious) methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};