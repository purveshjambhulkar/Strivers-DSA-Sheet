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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }

     int checkBalanced(TreeNode* root) {
        if (!root) return 0;

        int left = checkBalanced(root->left);
        if (left == -1) return -1;

        int right = checkBalanced(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        //Approach 1

        // if(root == NULL){
        //     return true;
        // }

        // bool l = isBalanced(root->left);
        // bool r = isBalanced(root->right);

        // bool diff = abs(height(root->left) - height(root->right)) <= 1;

        // if(l && r && diff){
        //     return true;
        // }else{
        //     return false;
        // }


        //Approach 2
        return checkBalanced(root) != -1;
    }
};