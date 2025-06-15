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
    void preorderUtil(TreeNode*& root, vector<int>& result) {
        if (root == NULL) {
            return;
        }

        result.push_back(root->val);
        preorderUtil(root->left, result);
        preorderUtil(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // Approach 1 - rescursive approach
        //  vector<int> result;
        //  preorderUtil(root , result);
        //  return result;

        // Approach 2 - Iterative approach
        // if (!root) {
        //     return {};
        // }
        // vector<int> result;
        // stack<TreeNode*> st;
        // st.push(root);

        // while (!st.empty()) {
        //     TreeNode* temp = st.top();
        //     st.pop();
        //     result.push_back(temp->val);
        //     if (temp->right) {
        //         st.push(temp->right);
        //     }
        //     if (temp->left) {
        //         st.push(temp->left);
        //     }
        // }

        // return result;


        //Approach 3 - Morris Traversal
         vector<int> result;
        TreeNode* cur = root;

        while (cur != nullptr) {
            if (cur->left == nullptr) {
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right != nullptr && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    result.push_back(cur->val); // Visit before creating thread
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }

        return result;

    }
};