#include <queue>
using namespace std;

class Solution {
public:
    void inorder(TreeNode* root, priority_queue<int>& pq, int k) {
        if (!root) return;

        inorder(root->left, pq, k);

        pq.push(root->val);

        if (pq.size() > k) {
            pq.pop();
        }

        inorder(root->right, pq, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq; 
        inorder(root, pq, k);
        return pq.top(); 
    }
};
