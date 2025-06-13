// problem link - https://www.geeksforgeeks.org/problems/children-sum-parent/1

class Solution {
  public:
    int isSumProperty(Node *root) {
        // Base case: empty tree or leaf node
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return 1;
        }
a
        int sum = 0;
        if (root->left) {
            sum += root->left->data;
        }

        if (root->right) {
            sum += root->right->data;
        }

        // Check current node and recursively check left and right subtree
        if (root->data == sum && 
            isSumProperty(root->left) && 
            isSumProperty(root->right)) {
            return 1;
        }

        return 0;
    }
};
