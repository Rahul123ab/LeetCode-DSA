class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {//TC=O(n), SC=O(n)
        int n = heights.size();
        vector<int> left(n,0); //left smaller nearest
        vector<int> right(n,0); //right smaller nearest
        stack<int> st;

        //calculating right smaller value
        for(int i=n-1; i>=0; i--) {//O(n)

            while(st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            // if(st.empty()) {
            //     right[i] = -1;
            // } else {
            //     right[i] = st.top();
            // }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        //calculating left smaller value
        for(int i=0; i<n; i++) {//O(n)

            while(st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            // if(st.empty()) {
            //     left[i] = -1;
            // } else {
            //     left[i] = st.top();
            // }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n ; i++) {//O(n)
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }

        return ans;
    }
};