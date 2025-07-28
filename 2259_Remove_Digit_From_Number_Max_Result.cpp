class Solution {
public:
    string removeDigit(string number, char digit) {
        string result="";

        for(int i=0; i<number.size(); i++) {
            if(number[i]== digit) {
                string curr = number.substr(0, i) + number.substr(i+1);
                result=max(result,curr);
            }
        }
        return result;
    }
};