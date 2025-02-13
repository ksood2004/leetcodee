#include <unordered_map>

class Solution {
public:
    unordered_map<int, int> mp; 
    
    bool findPair(TreeNode* root, int k) {
        if (!root) return false;

        if (mp.find(k - root->val) != mp.end()) {
            return true;
        }
        
   
        mp[root->val] = 1;

        return findPair(root->left, k) || findPair(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        mp.clear();  
        return findPair(root, k);
    }
};
