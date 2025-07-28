class Solution {
public:
    int singleNumber(vector<int>& nums) {
//Bitwise XOR will give 0 for same element i.e they cancel out each other and only single element will be left alone.
        int ans=0;
        
        for(int val: nums) {

            ans = ans ^ val; 
        }

        return ans;
    }
};