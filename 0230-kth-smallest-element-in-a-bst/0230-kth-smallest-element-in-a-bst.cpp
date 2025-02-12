class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (true) {
            // Go to the leftmost node
            while (root) {
                st.push(root);
                root = root->left;
            }
            
            // Process node
            root = st.top();
            st.pop();
            k--;

            if (k == 0) return root->val;

            // Move to the right subtree
            root = root->right;
        }
    }
};
