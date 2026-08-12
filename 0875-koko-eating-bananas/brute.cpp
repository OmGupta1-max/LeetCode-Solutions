//Let: n = number of piles, M = maximum pile
//We try: M different speeds.For each speed, we traverse all n piles.
//Therefore: Time Complexity = O(n × M)

// S.C = O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxPile = *max_element(piles.begin(), piles.end());

        for (int k = 1; k <= maxPile; k++) {

            int hours = 0;

            for (int pile : piles) {

                hours += (pile + k - 1) / k;
            }

            if (hours <= h)
                return k;
        }

        return -1;
    }
};
