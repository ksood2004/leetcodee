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
private:
//yeh member function hai
TreeNode* first;
TreeNode* last;
TreeNode* middle;
TreeNode* prev;
public:
void inorder(TreeNode* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    if(prev!=NULL && root->val < prev->val){
        // yaha first value hai jo ki change hi gyi hai
        if(first == NULL){
            first=prev;
            middle=root;
        }
        // yaha second value hai jo change hogi
        else{
            last=root;
        }
    }
    prev=root;
    inorder(root->right);
}
public:
    void recoverTree(TreeNode* root) {
       
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN); // agar pehli value nhi hai toh INT_MIN
        inorder(root);

        if(first && last){
            swap(first->val,last->val);
        }
        else if(first && middle){
            swap(first->val,middle->val );
        }
        
    }
};