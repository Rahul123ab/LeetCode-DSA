class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {//TC=O(n), SC=O(n)
        stack<int> st;
        vector<int> ans(nums.size(),-1);

        for(int i= 2*(nums.size())-1; i>=0; i--) {

            while(st.size() > 0 && nums[st.top()] <= nums[i%nums.size()]) {
                st.pop();
            }

            if(st.empty()) {
                ans[i%nums.size()] = -1;
            } else {
                ans[i%nums.size()] = nums[st.top()];
            }
            st.push(i%nums.size());
        }
        return ans;
    }
};