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
    
    void revPreorderUtil(TreeNode* root , int level , vector<int> &result){

        if(root == NULL){
            return;
        }

        if(level == result.size()){
            result.push_back(root->val);
        }

        revPreorderUtil(root->right , level+ 1 , result);
        revPreorderUtil(root->left , level+ 1 , result);

    }

    vector<int> rightSideView(TreeNode* root) {

        //Approach 1 - Iterative Traversal
        // if (!root) {
        //     return {};
        // }

        // vector<int> result;
        // queue<TreeNode*> q;
        // q.push(root);

        // while (!q.empty()) {
        //     int size = q.size();

        //     for (int i = 0; i < size; i++) {
        //         TreeNode* temp = q.front();
        //         q.pop();
        //         if (temp->left) {
        //             q.push(temp->left);
        //         }
        //         if (temp->right) {
        //             q.push(temp->right);
        //         }

        //         if (i == size - 1) {
        //             result.push_back(temp->val);
        //         }
        //     }
        // }

        // return result;


        //Approach 2 - Recursive Traversal
        vector<int> result;
        revPreorderUtil(root , 0, result);
        return result;
    }
};