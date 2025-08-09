class Solution {
public:
    int arrangeCoins(int n) {
        long left = 1, right = n;
        long result = 0;

        while(left <= right) {
            long mid = left + (right -left)/2;
            long coins = (long)(mid * (mid + 1)/2);

            if(coins > n) {
                right = mid - 1;
            } else {
                left = mid + 1;
                result = max(mid, result);
            }
        }
        return result;
    }
};