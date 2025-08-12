class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        //[rob1 , rob2, n, n+1, ....]
        for(int val : nums) {
            int temp = max(val + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;        
    }
};