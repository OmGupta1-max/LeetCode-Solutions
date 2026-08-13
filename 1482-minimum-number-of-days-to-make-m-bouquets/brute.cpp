class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        for (int day = 1; day <= maxDay; day++) {

            int bouquets = 0;
            int consecutive = 0;

            for (int flower : bloomDay) {

                if (flower <= day) {
                    consecutive++;

                    if (consecutive == k) {
                        bouquets++;
                        consecutive = 0;
                    }
                }
                else {
                    consecutive = 0;
                }
            }

            if (bouquets >= m)
                return day;
        }

        return -1;
    }
};
