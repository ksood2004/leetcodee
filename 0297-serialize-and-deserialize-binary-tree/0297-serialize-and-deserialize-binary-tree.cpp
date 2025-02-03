class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "#,";
        }

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                s.append("#,");
            } else {
                s.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        
        if (token == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(ss, token, ',')) {
                if (token != "#") {
                    node->left = new TreeNode(stoi(token));
                    q.push(node->left);
                }
            }

            if (getline(ss, token, ',')) {
                if (token != "#") {
                    node->right = new TreeNode(stoi(token));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};

