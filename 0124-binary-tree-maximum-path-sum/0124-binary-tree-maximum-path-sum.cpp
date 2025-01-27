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
int sum(TreeNode* root,int & karan){
    if(root==NULL){
        return 0;
    }
    int l=max(0,sum(root->left,karan));
    int r=max(0,sum(root->right,karan));
    karan=max(karan,l+r+root->val);
    return root->val+max(l,r);
}
    int maxPathSum(TreeNode* root) {
        int karan=INT_MIN;
        sum(root,karan);
        return karan;
    }
};