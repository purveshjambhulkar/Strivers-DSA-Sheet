//Approach 2 - Optimised Approach
class Solution {
public:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* second;
    TreeNode* prev;

    void inOrderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inOrderTraversal(root->left);

        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                second = root;
            }
        }
        prev = root;

        inOrderTraversal(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = NULL;
        middle = NULL;
        second = NULL;
        prev = NULL;

        inOrderTraversal(root);

        if (second != NULL) {
            std::swap(first->val, second->val);
        } else {
            std::swap(first->val, middle->val);
        }
    }
};



//Approach 1 - Brute Force - Inorder Traversal

// TLDR : simply find the inorder of the BST the sort the inorder , then agian do inorder traversal and correct the BST


// class Solution {
// public:

//     void inOrder(TreeNode*root , vector<int> &result){
//         if(!root){
//             return ;
//         }

//         inOrder(root->left , result);
//         result.push_back(root->val);
//         inOrder(root->right , result);
//     }


//     void inOrderAgain(TreeNode* root , vector<int>& result , int &index){
//         if(!root){
//             return ;
//         }

//         inOrderAgain(root->left , result , index);
//         root->val = result[index++];
//         inOrderAgain(root->right , result , index);
//     }

//     void recoverTree(TreeNode* root) {

//         vector<int> result;
//         inOrder(root, result);
//         sort(result.begin() , result.end());
//         int index = 0;
//         inOrderAgain(root, result , index);
    
//     }
// };