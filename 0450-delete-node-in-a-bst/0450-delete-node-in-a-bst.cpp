class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // Node has two children, find the inorder successor (smallest in right subtree)
                TreeNode* successor = root->right;
                while (successor->left) {
                    successor = successor->left;
                }
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};
