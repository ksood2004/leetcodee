class Solution {
public:
    int karan(TreeNode* root, int& res) {
        if (root == NULL) {
            return 0; // Base case: null nodes contribute 0 to the path sum
        }
        
        // Recursive calls for left and right children
        int l = max(0, karan(root->left, res));  // Max with 0 to ignore negative paths
        int r = max(0, karan(root->right, res)); // Max with 0 to ignore negative paths

        // Calculate maximum path sum passing through the current node
        int temp = max(l + root->val, r + root->val); // Max single-branch sum
        int ans = max(temp, l + r + root->val); // Max including both branches
        res = max(res, ans); // Update the global result

        return temp; // Return the max single-branch sum to parent
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN; // Initialize global maximum with smallest value
        karan(root, res);
        return res;
    }
};
