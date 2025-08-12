/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        q.push(root);

        while(q.size() > 0) {
            int qLen = q.size();
            vector<int> level;

            for(int j = 0; j < qLen; j++) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr != NULL) {
                    level.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if(level.size() > 0) {
                ans.push_back(level);
            }
        }
        return ans;        
    }
};