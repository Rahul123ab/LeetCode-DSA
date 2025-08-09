class Solution {
public:
    string simplifyPath(string path) {//TC=O(n), SC=O(n)
        stack<string> st;
        string curr = "";

        for(char ch : path + "/") {
            if(ch == '/') {
                if(curr == "..") {
                    if(!st.empty()) {
                        st.pop();
                    }
                } else if(curr != "" && curr != ".") {
                    st.push(curr);
                }
                curr = "";
            } else {
                curr += ch;
            }
        }
        // Build the simplified path from the stack
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result == "" ? "/" : result;
    }
};