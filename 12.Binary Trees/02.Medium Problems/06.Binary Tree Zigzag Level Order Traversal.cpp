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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> result;
        
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
            leftToRight = !leftToRight;
        }

        return result;
    }
};


// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         if(!root){
//             return {};
//         }
//         vector<vector<int>> result;
//         queue<TreeNode*> q;
//         q.push(root);
//         int currlevel = 1;

//         while(!q.empty()){
//             int size = q.size();
//             vector<int> level;

//             for(int i = 0 ; i < size ; i++){
//                 TreeNode* temp = q.front();
//                 q.pop();
//                 level.push_back(temp->val);

//                 if(temp->left){
//                     q.push(temp->left);
//                 }

//                 if(temp->right){
//                     q.push(temp->right);
//                 }
//             }

//             if(currlevel % 2 != 0){
//                 result.push_back(level);
//             }else{
//                 reverse(level.begin() , level.end());
//                 result.push_back(level);
//             }
//             currlevel++;
//         }

//         return result;

//     }
// };