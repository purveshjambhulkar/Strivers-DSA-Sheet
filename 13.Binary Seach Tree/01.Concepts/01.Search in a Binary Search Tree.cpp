/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if (!root) {
            return root;
        }

        while (root) {
            int temp = root->val;

            if (temp == val) {
                return root;
            } else if (temp > val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return NULL;
    }
};