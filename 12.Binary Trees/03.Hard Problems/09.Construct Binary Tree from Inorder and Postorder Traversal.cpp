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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inOrderMap;

        // Build map of inorder value -> index
        for (int i = 0; i < inorder.size(); i++) {
            inOrderMap[inorder[i]] = i;
        }

        return buildTreeUtil(inorder, 0, inorder.size() - 1,
                             postorder, 0, postorder.size() - 1, inOrderMap);
    }

private:
    TreeNode* buildTreeUtil(vector<int>& inorder, int inStart, int inEnd,
                            vector<int>& postorder, int postStart, int postEnd,
                            unordered_map<int, int>& inOrderMap) {
        // Base case: if the bounds are invalid
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        // Last element in postorder is root
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // Get index of root in inorder array
        int inRoot = inOrderMap[rootVal];

        // Number of elements in left subtree
        int leftTreeSize = inRoot - inStart;

        // Recursively build left and right subtrees
        root->left = buildTreeUtil(inorder, inStart, inRoot - 1,
                                   postorder, postStart, postStart + leftTreeSize - 1, inOrderMap);

        root->right = buildTreeUtil(inorder, inRoot + 1, inEnd,
                                    postorder, postStart + leftTreeSize, postEnd - 1, inOrderMap);

        return root;
    }
};
