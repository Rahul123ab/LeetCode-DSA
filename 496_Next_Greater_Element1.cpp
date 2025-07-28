class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> map;

        for(int i=nums2.size()-1; i>=0; i--) {

            while(st.size() > 0 && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) {
                map[nums2[i]]=-1;
            } else {
                map[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++) {
            ans.push_back(map[nums1[i]]);
        }
        return ans;
    }
};