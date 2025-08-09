class Solution {
public:
    int lengthOfLongestSubstring(string s) {//TC=O(n), SC=O(n)
        //sliding window + 2 ptr approach
        unordered_set<char> charSet;
        int left = 0;
        int result = 0;

        for(int right = 0; right < s.length(); right++) {

            while(charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            result = max(result, right - left + 1);
        }
        return result;
    }
};