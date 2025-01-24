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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; // To store the preorder traversal result
        if (root == nullptr) return ans; // If the tree is empty, return empty vector
        
        stack<TreeNode*> st; // Stack to store nodes during traversal
        st.push(root); // Start with the root node
        
        while (!st.empty()) {
            TreeNode* node = st.top(); // Get the top node
            st.pop();
            ans.push_back(node->val); // Add the current node's value to the result
            
            // Push right child first so that left child is processed first
            if (node->right != nullptr) {
                st.push(node->right);
            }
            if (node->left != nullptr) {
                st.push(node->left);
            }
        }
        
        return ans; // Return the preorder traversal result
    }
};
