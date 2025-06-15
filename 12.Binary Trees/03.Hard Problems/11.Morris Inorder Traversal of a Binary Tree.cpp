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
    void inorderUtil(TreeNode* root , vector<int>&result){
        if(root ==NULL){
            return;
        }

        inorderUtil(root->left ,result);
        result.push_back(root->val);
        inorderUtil(root->right ,result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        //Approach 1 - Recursive Approach
        // vector<int> ans;
        // inorderUtil(root , ans);
        // return ans;

        //Approach 2 - Iterative Approach

        // if(!root){
        //     return {};
        // }

        // stack<TreeNode*> st;
        // vector<int> result;
        // TreeNode* node = root;

        // while(true){
        //     if(node != NULL){
        //         st.push(node);
        //         node = node->left;
        //     }else{
        //         if(st.empty()){
        //             break;
        //         }

        //         node = st.top();
        //         st.pop();
        //         result.push_back(node->val);
        //         node = node->right;

        //     }


        // }
        // return result;

        //Approach 3 - Morris Traversal

        vector<int> inorder;
        TreeNode* cur = root;

        while (cur != nullptr) {
            if (cur->left == nullptr) {
                // No left child, visit this node and go right
                inorder.push_back(cur->val);
                cur = cur->right;
            } else {
                // Find the inorder predecessor of current
                TreeNode* prev = cur->left;
                while (prev->right != nullptr && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    // Make current the right child of its predecessor
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // Revert the changes made and visit current
                    prev->right = nullptr;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return inorder;

        
    }
};