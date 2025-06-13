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
    void preorderUtil(TreeNode* root, int& count) {
        if (root == NULL) {
            return;
        }

        count++;
        preorderUtil(root->left, count);
        preorderUtil(root->right, count);
    }

    int countNodes(TreeNode* root) {

        // Approach 1 - Brute Force

        // int count = 0;
        // preorderUtil(root , count);
        // return count;
        

        //Approach 2 - Optimal (less than O(n))
        if (root == NULL) {
            return 0;
        }

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if (lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findLeftHeight(TreeNode* node) {
        int hght = 0;
        while (node) {
            hght++;
            node = node->left;
        }
        return hght;
    }

    int findRightHeight(TreeNode* node) {
        int hght = 0;
        while (node) {
            hght++;
            node = node->right;
        }
        return hght;
    }
};