class Solution {
public:
struct Node {
        int leftChar;
        int rightChar;
        int leftMax;
        int rightMax;
        int maxLen;
        int len;
        Node() {
            leftChar = rightChar = 0;
            leftMax = rightMax = maxLen = len = 0;
        }
    };
    vector<Node> tree;
    string s;
    Node merge(Node a, Node b) {
        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Longest prefix
        res.leftMax = a.leftMax;

        if (a.leftMax == a.len && a.rightChar == b.leftChar) {
            res.leftMax = a.len + b.leftMax;
        }

        // Longest suffix
        res.rightMax = b.rightMax;

        if (b.rightMax == b.len && a.rightChar == b.leftChar) {
            res.rightMax = b.len + a.rightMax;
        }

        // Best answer completely inside left/right
        res.maxLen = max(a.maxLen, b.maxLen);

        // Check if a repeating sequence crosses the middle
        if (a.rightChar == b.leftChar) {
            res.maxLen = max(res.maxLen,
                             a.rightMax + b.leftMax);
        }

        return res;
    }

    void build(int node, int l, int r) {

        if (l == r) {
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];

            tree[node].leftMax = 1;
            tree[node].rightMax = 1;
            tree[node].maxLen = 1;
            tree[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int index, char ch) {

        if (l == r) {
            tree[node].leftChar = ch;
            tree[node].rightChar = ch;
            tree[node].leftMax = 1;
            tree[node].rightMax = 1;
            tree[node].maxLen = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, ch);
        }
        else {
            update(node * 2 + 1, mid + 1, r, index, ch);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];

            // Update one character
            update(1, 0, n - 1, index, ch);

            // Root contains the answer for the whole string
            ans.push_back(tree[1].maxLen);
        }

        return ans;
    }
};