class Solution {
public:

    vector<string> answer;

    void generate(string &current, int open, int close, int n) {

        // Base Case
        if (current.length() == 2 * n) {
            answer.push_back(current);
            return;
        }

        // Choice 1: Add an opening bracket
        if (open < n) {
            current.push_back('(');

            generate(current, open + 1, close, n);

            // Backtrack
            current.pop_back();
        }

        // Choice 2: Add a closing bracket
        if (close < open) {
            current.push_back(')');

            generate(current, open, close + 1, n);

            // Backtrack
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        string current = "";

        generate(current, 0, 0, n);

        return answer;
    }
};