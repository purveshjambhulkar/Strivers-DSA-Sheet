//Approach 3 - BSTIterator

//TLDR - use BSTIterator ..

class BSTIterator {
    stack<TreeNode*> myStack;
    bool reverse;

    void pushAll(TreeNode* node) {
        while (node) {
            myStack.push(node);
            node = reverse ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }

    int next() {
        TreeNode* curr = myStack.top();
        myStack.pop();
        if (reverse)
            pushAll(curr->left);
        else
            pushAll(curr->right);
        return curr->val;
    }

    bool hasNext() {
        return !myStack.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }

        return false;
    }
};



// Approach 2 - prefix sum method

//TLDR - maintian  prefix sum data structure to store node which have been visited and for curr node check if the curr->val - k exists in the data structure or not , if yes return true or else add that curr node in that ds

// class Solution {
// public:
//     void traverse(TreeNode* root, int k, std::unordered_set<int>& seen_values, bool& found_pair) {
//         if (root == NULL || found_pair) {
//             return;
//         }

//         int complement = k - root->val;

//         if (seen_values.count(complement)) {
//             found_pair = true;
//             return;
//         }

//         seen_values.insert(root->val);

//         traverse(root->left, k, seen_values, found_pair);
//         traverse(root->right, k, seen_values, found_pair);
//     }

//     bool findTarget(TreeNode* root, int k) {
//         std::unordered_set<int> seen_values;
//         bool found_pair = false;

//         traverse(root, k, seen_values, found_pair);
//         return found_pair;
//     }
// };

// Approach 1 - Brute force

// TLDR : simply find inorder of the BST and the apply normal 2Sum on it using 2
// ptr

// class Solution {
// public:
//     void inOrder(TreeNode* root, vector<int>& inorder) {
//         if (root == NULL) {
//             return;
//         }

//         inOrder(root->left, inorder);
//         inorder.push_back(root->val);
//         inOrder(root->right, inorder);
//     }

//     bool check2Sum(vector<int> inorder, int k) {
//         int left = 0;
//         int right = inorder.size() - 1;
//         while (left < right) {
//             int temp = inorder[left] + inorder[right];

//             if (temp == k) {
//                 return true;
//             } else if (temp < k) {
//                 left++;
//             } else {
//                 right--;
//             }
//         }

//         return false;
//     }

//     bool findTarget(TreeNode* root, int k) {

//         vector<int> inorder;
//         inOrder(root, inorder);
//         return check2Sum(inorder, k);
//     }
// };