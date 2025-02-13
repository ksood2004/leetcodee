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
TreeNode* karan(vector<int>& hello,int &i,int bound) {
    if(i==hello.size() || hello[i]>bound){
        return NULL;
    }
    TreeNode* root=new TreeNode(hello[i++]) ;
    root->left=karan(hello,i,root->val);
    root->right=karan(hello,i,bound);
    return root;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return karan(preorder,i,INT_MAX);
    }
};