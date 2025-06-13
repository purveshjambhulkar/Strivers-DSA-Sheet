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
    void markParents(TreeNode* root, TreeNode* target, int k,
                     unordered_map<TreeNode*, TreeNode*>& parent_map) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp->left) {
                parent_map[temp->left] = temp;
                q.push(temp->left);
            }

            if (temp->right) {
                parent_map[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // first level order traversal to mark all the parents
        unordered_map<TreeNode*, TreeNode*> parent_map;
        markParents(root, target, k, parent_map);

        unordered_map<TreeNode*, int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = 1;
        int level = 0;

        while (!q.empty()) {
            if (level++ == k)
                break;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left && !visited[temp->left]) {
                    q.push(temp->left);
                    visited[temp->left] = 1;
                }

                if (temp->right && !visited[temp->right]) {
                    q.push(temp->right);
                    visited[temp->right] = 1;
                }

                if (parent_map[temp] && !visited[parent_map[temp]]) {
                    q.push(parent_map[temp]);
                    visited[parent_map[temp]] = 1;
                }
            }
        }

        vector<int> result;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }

        return result;
    }
};