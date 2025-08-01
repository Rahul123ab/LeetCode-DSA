class Solution {
public:
    int mySqrt(int x) {

        if(x < 2) {
            return x;
        }

        int start=1;
        int end=x/2;
        int result=0;

        while (start <= end) {
            int mid = start + (end-start)/2;
            
            if((long long)mid*mid == x) {
                return mid;
            } else if ((long long)mid*mid < x) {
                result = mid;
                start = mid + 1 ;
            } else {
                end = mid - 1;
            }
        }
        return result;
    }
};