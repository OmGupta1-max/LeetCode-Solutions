//USING HASHMAP(UNORDERD_MAP)
//T.C = O(N) AND S.C = O(N)
//Better Solution :-
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> mp;

        for(int x : nums)
          mp[x]++;

        for(auto it : mp) {
           if(it.second > 1)
           return true;
        }

         return false;
    }
};
