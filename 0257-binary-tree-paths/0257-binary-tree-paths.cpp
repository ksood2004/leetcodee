
class Solution {
public:
    void helper(TreeNode* root, string path, vector<string>& result) {
        if (!root) return;
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);

        if (!root->left && !root->right) {
            result.push_back(path);
        } else {
            helper(root->left, path, result);
            helper(root->right, path, result);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        helper(root, "", result);
        return result;
    }
};
