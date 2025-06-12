
//Approach 2 - Recursive Approach
class Solution {
public:
    bool Util(TreeNode* lefty , TreeNode* righty){
        if (!lefty && !righty) return true;
        if (!lefty || !righty) return false;
        if (lefty->val != righty->val) return false;

        return Util(lefty->left , righty->right) &&
               Util(lefty->right , righty->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return Util(root->left , root->right);
    }
};

//Apprach 1 - Iterative
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root) return true;

//         queue<pair<TreeNode*, TreeNode*>> q;
//         q.push({root->left, root->right});

//         while (!q.empty()) {
//             auto [left, right] = q.front();
//             q.pop();

//             if (!left && !right) continue;
//             if (!left || !right) return false;
//             if (left->val != right->val) return false;

//             q.push({left->left, right->right});
//             q.push({left->right, right->left});
//         }

//         return true;
//     }
// };
