// Approach 2 -

// TLDR - take stack and then push all the left elements of the current root node in it , for next function - pop the top of stack and put all its left element of top->right in the stack and return the value of top(curr)
//has next - simply check is stack is empty or not

class BSTIterator {
public:
    stack<TreeNode*> st;


     void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) {
         pushAllLeft(root);
    }

    int next() {
          TreeNode* current = st.top();
        st.pop();
        pushAllLeft(current->right);
        return current->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

// Approach 1 - Uses extra space for inorder vector

// TLDR - simply find the inorder of the tree and use it return the next and the
// has next , Simple!

// class BSTIterator {
// public:
//     vector<TreeNode*> inorder;
//     int index = 0;
//     void inOrder(TreeNode* root, vector<TreeNode*>& inorder) {
//         if (!root) {
//             return;
//         }

//         inOrder(root->left, inorder);
//         inorder.push_back(root);
//         inOrder(root->right, inorder);
//     }

//     BSTIterator(TreeNode* root) { inOrder(root, inorder); }

//     int next() { return inorder[index++]->val; }

//     bool hasNext() { return index < inorder.size(); }
// };
