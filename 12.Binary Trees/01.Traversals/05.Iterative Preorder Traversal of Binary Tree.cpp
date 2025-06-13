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
        if (!root) {
            return {};
        }
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            result.push_back(temp->val);
            if (temp->right) {
                st.push(temp->right);
            }
            if (temp->left) {
                st.push(temp->left);
            }
        }

        return result;
    }
};