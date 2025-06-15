class Solution {
public:
    TreeNode* maxValue(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            } else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* pred = maxValue(root->left);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val); // delete pred node
            }
        }
        return root;
    }
};