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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // //Approach 1
        // if ((p != NULL && q == NULL) || (p == NULL && q != NULL)){
        //     return false;
        // }
        // if(p == NULL && q == NULL){
        //     return true;
        // }

        // bool left = isSameTree(p->left , q->left);
        // bool right = isSameTree(p->right , q->right);

        // bool val = p->val == q->val;

        // if(left && right && val){
        //     return true;
        // }else{
        //     return false;
        // }

        // Same approach but shorter code

        if (p == NULL || q == NULL) {
            return p == q;
        } else
            return (p->val == q->val) && isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
    }
};