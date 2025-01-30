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
void treee(TreeNode* root,int level,vector<int>& karan){
    if(root==NULL){
        return;
    }
   
    // int l=tree(root->left,level);
    // int r=tree(root->right,level);

    if(level==karan.size()){
        karan.push_back(root->val);
    }
    treee(root->right,level+1,karan);
    treee(root->left,level+1,karan);

}
    vector<int> rightSideView(TreeNode* root) {
        int level=0;
        vector<int> ans;
        treee(root,level,ans);
        return ans;

        
    }
};