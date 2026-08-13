class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int bouquets = 0;
        int consecutive = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= day) {
                consecutive++;
            }
            else {
                consecutive = 0;
            }

            if (consecutive == k) {
                bouquets++;
                consecutive = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};