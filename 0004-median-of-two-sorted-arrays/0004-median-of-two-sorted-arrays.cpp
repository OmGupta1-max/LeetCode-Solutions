class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged;
        int i = 0;
        int j = 0;
        // Merge both arrays
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            }
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        // Remaining elements of nums1
        while (i < n) {
            merged.push_back(nums1[i]);
            i++;
        }
        // Remaining elements of nums2
        while (j < m) {
            merged.push_back(nums2[j]);
            j++;
        }
        int total = n + m;
        // Odd
        if (total % 2 == 1) {
            return merged[total / 2];
        }
        // Even
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    }
};