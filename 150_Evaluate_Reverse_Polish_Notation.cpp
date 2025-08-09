class Solution {
public:
    int evalRPN(vector<string>& tokens) {//TC=O(n), SC=O(n)
        stack<int> st;

        for(string s : tokens) {
            if(s == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b+a);
            } else if(s == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
            } else if (s == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b*a);
            } else if (s == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};