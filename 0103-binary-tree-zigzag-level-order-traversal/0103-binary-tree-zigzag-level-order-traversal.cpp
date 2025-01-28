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
void bfs(TreeNode* root,int level,vector<vector<int>>& karan,bool& flag){
    if(root==NULL){
        return;
    }
    if(karan.size()<=level){
        karan.push_back({});
    }
    if(level%2==0){
        karan[level].push_back(root->val);
    }
    else{
        karan[level].insert(karan[level].begin(),root->val);
    }
    bfs(root->left,level+1,karan,flag);
    bfs(root->right,level+1,karan,flag);
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> karan;
        if(root==NULL){
            return karan;
        }
        bool flag=true;
        int level=0;
     bfs(root,level,karan,flag);
     return karan;
        
    }
};