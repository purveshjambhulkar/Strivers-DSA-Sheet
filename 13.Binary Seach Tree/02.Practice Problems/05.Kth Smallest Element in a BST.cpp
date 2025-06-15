/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrderUtil(TreeNode* root ,vector<int> &inorder){
        if(root == NULL){
            return;
        }

        inOrderUtil(root->right , inorder);
        inorder.push_back(root->val);
        inOrderUtil(root->left , inorder);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> inorder;
        inOrderUtil(root , inorder);
        return inorder[inorder.size() - k];















    }
};