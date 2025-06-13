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
    void postorderUtil(TreeNode*& root, vector<int>& result) {

        if (root == NULL) {
            return;
        }

        postorderUtil(root->left, result);
        postorderUtil(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        // Approach 1 - Recursive Traversal
        //  vector<int> result;
        //  postorderUtil(root , result);
        //  return result;

        // Approach 2 - Iterative Approach - 2 stack approach

        // if (!root)
        //     return {};
        // stack<TreeNode*> st1;
        // stack<TreeNode*> st2;
        // vector<int> result;
        // st1.push(root);

        // while (!st1.empty()) {
        //     TreeNode* temp = st1.top();
        //     st1.pop();
        //     st2.push(temp);

        //     if (temp->left) {
        //         st1.push(temp->left);
        //     }

        //     if (temp->right) {
        //         st1.push(temp->right);
        //     }
        // }

        // while (!st2.empty()) {
        //     result.push_back(st2.top()->val);
        //     st2.pop();
        // }

        // return result;

        // Approach 3 - Iterative Approach - Optimising SC by using one stack
        // only

        if (!root)
            return {};
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            result.push_back(temp->val);

            if(temp->left){
                st.push(temp->left);
            }

            if(temp->right){
                st.push(temp->right);
            }


        }


        reverse(result.begin() , result.end());

        return result;
        
    }
};