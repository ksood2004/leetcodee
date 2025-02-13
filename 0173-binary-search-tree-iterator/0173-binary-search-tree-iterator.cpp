// #include <stack>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class BSTIterator {
private:
    stack<TreeNode*> st;

    // Helper function to push all left nodes to the stack
    void pushALL(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushALL(root);  // Initialize by pushing leftmost nodes
    }
   
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushALL(node->right);  // Push leftmost nodes of the right subtree
        return node->val;      // Return the in-order value
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
