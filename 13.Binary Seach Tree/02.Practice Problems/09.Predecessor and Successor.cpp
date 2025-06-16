class Solution {
public:
    // Helper function to find predecessor and successor using inorder traversal
    void findPreSucInorder(Node* root, int key, Node*& pre, Node*& succ) {
        if (root == NULL) {
            return;
        }

        // Recurse left
        findPreSucInorder(root->left, key, pre, succ);

        // Process current node
        // If current node's data is less than key, it could be a predecessor
        if (root->data < key) {
            pre = root; // This is the new best candidate for predecessor
        }
        // If current node's data is greater than key, it could be a successor
        // Since we are doing inorder, the *first* node we find with data > key
        // will be the smallest such node.
        else if (root->data > key) {
            // Once we find a node greater than key, it's our successor.
            // Any subsequent nodes in the right subtree would be even larger.
            // We set it and can then return to optimize.
            // However, a more robust way is to just set it and let recursion unwind.
            // If succ is already set, it means we found an earlier (smaller) successor
            // so we don't update it unless it's null or a better candidate.
            // For a strict BST, the *first* one encountered in inorder > key is the successor.
            if (succ == NULL) { // Only set succ if it hasn't been set yet
                succ = root;
            }
            // An early return here is often used to optimize once successor is found,
            // but it needs careful placement to not miss the predecessor.
            // For simplicity and correctness with the existing logic structure,
            // let's stick to setting 'succ' and allowing the right traversal.
            // The best optimization is to not traverse right if succ is found in left.
            // But this function structure means we need to visit all nodes.
        }

        // Recurse right
        // Crucially, we only recurse right if the successor hasn't been found OR
        // if the current node's data is less than or equal to the key.
        // If we found a successor in the left subtree, we don't need to go right.
        if (root->data <= key || succ == NULL) { // Go right if current is <= key OR if we still need a successor
            findPreSucInorder(root->right, key, pre, succ);
        }
    }


    // Alternative and more typical iterative or two-pass approach for clarity and efficiency
    // This avoids some of the complexities of managing state in a single inorder pass.
    Node* findPredecessor(Node* root, int key) {
        Node* pre = NULL;
        while (root != NULL) {
            if (root->data < key) {
                pre = root; // This is a candidate, try to find a larger one in the right subtree
                root = root->right;
            } else {
                root = root->left; // Go left to find a smaller candidate or if current is >= key
            }
        }
        return pre;
    }

    Node* findSuccessor(Node* root, int key) {
        Node* succ = NULL;
        while (root != NULL) {
            if (root->data > key) {
                succ = root; // This is a candidate, try to find a smaller one in the left subtree
                root = root->left;
            } else {
                root = root->right; // Go right to find a larger candidate or if current is <= key
            }
        }
        return succ;
    }

    std::vector<Node*> findPreSuc(Node* root, int key) {
        // Option 1: Using the combined inorder traversal (modified version)
        // Node* pre = NULL; // Initialize to NULL
        // Node* succ = NULL; // Initialize to NULL
        // findPreSucInorder(root, key, pre, succ);
        // return {pre, succ};

        // Option 2: Using separate iterative functions (often cleaner)
        Node* pre = findPredecessor(root, key);
        Node* succ = findSuccessor(root, key);
        return {pre, succ};
    }
};