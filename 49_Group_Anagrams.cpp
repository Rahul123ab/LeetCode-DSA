class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {//TC=SC=O(m * n) n is the max length of string
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;

        if(strs.size() == 0) {
            return ans;
        }
        
        for(string s : strs) {
            // Count frequency of each character (only lowercase letters)
            vector<int> count(26,0);
            for (char ch : s) {//
                count[ch - 'a']++;
            }

            // Build a unique key like "1#0#0#0#1#..." from the frequency array
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += '#' + to_string(count[i]); // '#' avoids key ambiguity like 11 vs 1 1
            }
            map[key].push_back(s);
        }

        // Populate the final ans
        for (auto& pair : map) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};