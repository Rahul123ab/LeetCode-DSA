class Solution {
public:
    int reverse(int x) {
        
        long ans=0;
        int rem=0;

        while(x != 0) {
            
            rem = x%10;
            x=x/10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && rem > 7)) return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && rem < -8)) return 0;
            
            ans = ans*10 + rem;
        }
        return ans;
    }
};