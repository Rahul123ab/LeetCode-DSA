class Solution {
public:
    string convert(string s, int numRows) {//TC=O(n)
        string res ="";

        if(numRows == 1) {
            return s;
        }

        for(int i = 0; i < numRows; i++) {

            int increment = 2 * (numRows - 1);//this gives the no of chars to jump to get next char in the same row

            for(int j = i; j < s.length(); j = j + increment) {
                
                res += s[j];

                if(i > 0 && i < (numRows - 1) && (j+ increment - 2 * i < s.length())) { //so that this doesn't go out of bound
                    res += s[j+ increment - 2 * i];
                }
            }
        }
        return res;
    }
};