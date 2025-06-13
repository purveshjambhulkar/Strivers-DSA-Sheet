class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;

        // Build a map from inorder values to their indices
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1, inMap);
    }

private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int, int>& inMap) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];
        int leftTreeSize = inRoot - inStart;

        root->left = build(preorder, preStart + 1, preStart + leftTreeSize,
                           inorder, inStart, inRoot - 1, inMap);
        root->right = build(preorder, preStart + leftTreeSize + 1, preEnd,
                            inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};