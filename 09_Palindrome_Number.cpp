class Solution {
public:
    bool isPalindrome(int x) {
        
        long rev = 0;
        int n = x;

        while(n > 0) {
            
            int remainder = n%10;
            rev = rev*10 + remainder;
            n = n/10;
        }

        if(rev == x)
            return true;
        return false;
    }
};