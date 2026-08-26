// T.C. = O(n X S)
// S.C = O(1)

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = *max_element(weights.begin(),weights.end());
        int totalWeight = 0;
        for (int w : weights)
            totalWeight += w;
        for (int capacity = maxWeight;
             capacity <= totalWeight;
             capacity++) {
            int currentWeight = 0;
            int requiredDays = 1;
            for (int w : weights) {
                if (currentWeight + w <= capacity) {
                    currentWeight += w;
                }
                else {
                    requiredDays++;
                    currentWeight = w;
                }
            }
            if (requiredDays <= days)
                return capacity;
        }
        return -1;
    }
};
