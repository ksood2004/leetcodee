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
int karan(TreeNode* root,int &res){
     if(root==NULL){
            return 0;
        }
        int l=karan(root->left,res);
        int r=karan(root->right,res);
        res=max(res,l+r);
        return max(l,r)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        int res=INT_MIN;
        karan(root,res);
        return res;
       
        
    }
};