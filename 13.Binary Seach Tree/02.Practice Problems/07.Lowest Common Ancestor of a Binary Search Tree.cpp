/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        if(root == NULL){
            return root;
        }

        int temp = root->val;

        //if both p and q lies to left then go to left
        if(p->val < temp && q->val < temp){
            return lowestCommonAncestor(root->left , p , q);
        }

        //or if both p and q lies to right then go to right
        if(p->val > temp && q->val > temp){
            return lowestCommonAncestor(root->right ,p , q);
        }

        //if p lies on left and q lies on right or vice versa
        return root;



































    }
};