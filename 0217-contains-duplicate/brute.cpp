class Solution {
public:
    bool isAnagram(string s, string t) {
        for(int i = 0; i < n; i++) {
           for(int j = i + 1; j < n; j++) {
             if(nums[i] == nums[j])
                return true;
       }
    }
       return false;
    }
};
