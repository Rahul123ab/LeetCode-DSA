class Solution {
public:
    bool isPalindrome(int x) {
        long rev = 0;
        int n = x;

        while(n > 0) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n = n/10;
        }
        if (rev == x) {
            return true;
        } 
        return false;
    }
};
