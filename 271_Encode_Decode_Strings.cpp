class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string val : strs) {
            encoded +=to_string(val.length()) + '#' + val;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int start = 0;
        int end = s.length() - 1;
        while(start <= end) {
            int j = start;
            // Find the delimiter `#`
            while(s[j] != '#') {
                j++;
            }
            // Extract length
            int len = stoi(s.substr(start, j - start));

            // Extract the actual string
            string word = s.substr(j + 1, len);
            decoded.push_back(word);

            // Move to the next encoded word
            start = j + 1 + len;
        }
        return decoded;
    }
};
