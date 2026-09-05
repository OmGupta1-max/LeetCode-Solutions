class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        int medianIndex = total / 2;
        int i = 0;
        int j = 0;
        int previous = -1;
        int current = -1;
        for (int count = 0; count <= medianIndex; count++) {
            previous = current;
            if (i < n && j < m) {
                if (nums1[i] <= nums2[j]) {
                    current = nums1[i];
                    i++;
                }
                else {
                    current = nums2[j];
                    j++;
                }
            }
            else if (i < n) {
                current = nums1[i];
                i++;
            }
            else {
                current = nums2[j];
                j++;
            }
        }
        // Odd number of elements
        if (total % 2 == 1) {
            return current;
        }
        // Even number of elements
        return (previous + current) / 2.0;
    }
};