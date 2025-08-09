class Solution {
public:
    string largestOddNumber(string num) { //TC=O(n)
        for(int i= num.size()-1; i>=0; i--) {
            
            if((num[i] - '0')%2 !=0) { // '7' - '0' meaning '7' - '0' = 55 - 48 = 7 ASCII values
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};