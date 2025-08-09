class Solution {
public:
    string minWindow(string s, string t) {
        //check if input t is an empty string
        if(t.empty()) {
            return "";
        }

        unordered_map<char, int> countT, window;
        //populate the countT with the t chars
        for(char ch : t) {
            countT[ch]++;
        }

        int left = 0, have = 0;
        int need = countT.size();
        pair<int, int> result = {-1, -1};
        int resLen = INT_MAX;
        //start the sliding window from left to right by moving one char at a time
        for(int right = 0; right < s.length(); right++) {
            char ch = s[right];
            window[ch]++;

            //check if the curr char alredy exists in the countT and in the same freq as needed
            if(countT.count(ch) && window[ch] == countT[ch]) {
                have++;
            }

            while(have == need) {
                //populate the result
                if((right - left + 1) < resLen) {
                    result = {left, right};
                    resLen = right - left + 1;
                }
                //pop from the left of the window
                window[s[left]]--;

                //check if after poping the left window element is window count is still valid
                if(countT.count(s[left]) && window[s[left]] < countT[s[left]]) {
                    have--;
                }
                left++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(result.first, resLen);
    }
};