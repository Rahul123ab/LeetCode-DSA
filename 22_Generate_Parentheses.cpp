class Solution {
public:

    void backtrack(int openN, int closedN, int n, 
        vector<string>& result, string& stack) {

            if(openN == closedN && openN == n) {
                result.push_back(stack);
                return;
            }

            if(openN < n) {
                stack += '(';
                backtrack(openN+1, closedN, n, result, stack);
                stack.pop_back();
            }
            if(closedN < openN) {
                stack += ')';
                backtrack(openN, closedN+1, n, result, stack);
                stack.pop_back();
            }
    }

    vector<string> generateParenthesis(int n) {
        //only add open parenthesis if open < n
        //only add a closing parenthesis if closed < open
        //valid if open == closed == n
        string stack;
        vector<string> result;
        backtrack(0, 0, n, result, stack);
        return result;   
    }
};