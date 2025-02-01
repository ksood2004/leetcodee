class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            long long curr = q.front().second;
            long long first, last;
            
            for (int i = 0; i < size; i++) {
                long long hello = q.front().second - curr;
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0) {
                    first = hello;
                }
                if (i == size - 1) {
                    last = hello;
                }
                if (node->left) {
                    q.push({node->left, hello * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, hello * 2 + 2});
                }
            }        
            ans = max(ans, int(last - first + 1));
        }
        return ans; 
    }
};
