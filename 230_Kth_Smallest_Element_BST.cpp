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
    int counter = 0;

    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) {
            return -1;
        }

        if(root->left != NULL) { //left
           int left = kthSmallest(root->left, k);
           if(left != -1) {
            return left;
           }
        }

        if(counter+1 == k) {//root
            return root->val;
        }
        counter++;

        if(root->right != NULL) {//right
            int right = kthSmallest(root->right, k);
            if(right != -1) {
                return right;
            }
        }
        return -1;
    }
};