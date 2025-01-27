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
int karan(TreeNode* root,int& hello ){
    if(root==NULL){
        return 0;
    }
    int l=karan(root->left,hello);
    int r=karan(root->right,hello);
    hello=max(hello,l+r);
    return 1+max(l,r);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int hello=INT_MIN;
        karan(root,hello);
        return hello;
    }
};