class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;

        for(auto &val : s) {
            map1[val]++;
        }
        for(auto &val : t) {
            map2[val]++;
        }
        return map1==map2;
    }
};