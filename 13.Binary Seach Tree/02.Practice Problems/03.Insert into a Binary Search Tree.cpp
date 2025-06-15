class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        TreeNode* current = root;

        while (true) {
            if (val < current->val) {
                if (current->left) {
                    current = current->left;
                } else {
                    current->left = new TreeNode(val);
                    break;
                }
            } else {
                if (current->right) {
                    current = current->right;
                } else {
                    current->right = new TreeNode(val);
                    break;
                }us
            }
        }

        return root;
    }
};
