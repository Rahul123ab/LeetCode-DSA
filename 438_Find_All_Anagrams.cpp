class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //check if the length of p is greater than the string S.
        if(p.length() > s.length()) {
            return {};
        }

        unordered_map<char, int> pCount, sCount;
        vector<int> result;
        //initialize the first set of chars from both the strings
        for(int i = 0; i < p.length(); i++) {
            pCount[p[i]]++;
            sCount[s[i]]++;
        }
        //check if the first set of chars matches then its anagram
        if(pCount == sCount) {
            result.push_back(0);
        }
        //perform the sliding window on the remaining chars of string s
        int left = 0;
        for(int right = p.length(); right < s.length(); right++) {
            sCount[s[right]]++;
            sCount[s[left]]--;

            //if at anytime char count is reduced to 0 we can erase it from map so as to compare exactly the chars in string p
            if(sCount[s[left]] == 0) {
                sCount.erase(s[left]);
            }
            left++;
            //if chars in both the maps are exactly the same along with freq we can add the starting index to result
            if(pCount == sCount) {
                result.push_back(left);
            }
        }
        return result;
    }
};