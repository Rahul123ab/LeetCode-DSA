class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0) return 1.0;
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;
        if(x == -1 && n%2 == 0) return 1.0;
        if(x == -1 && n%2 != 0) return -1.0;

        long binForm=n;
        if(n < 0 ){
            x=1/x;
            binForm = -binForm;
        }
        double res=1;

        while( binForm > 0 ) {
            if(binForm % 2 == 1){
                res *=x;
            }
            x *= x;
            binForm /=2;
        }
        return res;
        
    }
};