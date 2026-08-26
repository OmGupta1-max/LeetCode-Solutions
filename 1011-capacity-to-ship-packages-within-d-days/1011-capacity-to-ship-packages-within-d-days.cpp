class Solution {
public:

    bool possible(vector<int>& weights,int capacity,int days) {
        int requiredDays = 1;
        int currentWeight = 0;
        for (int weight : weights) {
            if (currentWeight + weight <= capacity) {
                currentWeight += weight;
            }
            else {
                requiredDays++;
                currentWeight = weight;
            }
        }
        return requiredDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate( weights.begin(),weights.end(),0);
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (possible(weights, mid, days))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};