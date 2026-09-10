class Solution {
public:
    int lower_bound(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int ans=-1;
        sort(arr.begin(), arr.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& matrix) {
        int maxi = 0;
        int index = 0;
        int m = matrix.size();

        for (int i = 0; i < matrix.size(); i++) {
            int n = matrix[i].size();
            int y = lower_bound(matrix[i], 1);
            if (y == -1)
                continue;
            int numberof1s = n - y;
            if (numberof1s > maxi) {
                maxi = numberof1s;
                index = i;
            }
        }
        return {index, maxi};
    }
};