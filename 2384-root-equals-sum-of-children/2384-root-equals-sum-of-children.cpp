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
    bool checkTree(TreeNode* root) {
   if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return true;
        }

        int total = 0;
        if (root->left) {
            total += root->left->val;
        }
        if (root->right) {
            total += root->right->val;
        }
        if (total != root->val) {
            return false;
        }
        return checkTree(root->left) && checkTree(root->right);
    }

};