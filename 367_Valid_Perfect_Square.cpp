class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==1) {
            return true;
        }
        int start=1;
        int end=num/2;

        while (start <= end) {

            int mid = start + (end-start)/2;

            if((long long) mid * mid == num) {
                return true;
            } else if ((long long) mid * mid < num) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
};