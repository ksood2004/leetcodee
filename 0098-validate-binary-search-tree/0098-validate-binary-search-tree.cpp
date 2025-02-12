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
bool karan(TreeNode* root,long MIN,long MAX){
    if(root==NULL){
        return true;
    }
    if(root->val <=MIN || root->val>=MAX){
        return false;
    }

    return karan(root->left,MIN,root->val) && karan(root->right,root->val,MAX);
}
    bool isValidBST(TreeNode* root) {
        return karan(root,LONG_MIN,LONG_MAX);

        
    }
};