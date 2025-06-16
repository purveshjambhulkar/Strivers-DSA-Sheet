// Problem link - https://www.geeksforgeeks.org/problems/largest-bst/1



//Approach 2 - Optimal approach

class Solution {
public:
    int max_bst_size;

    struct NodeProperties {
        int min_val;
        int max_val;
        int size;
        bool is_bst;
    };

    NodeProperties solve(Node* root) {
        if (root == nullptr) {
            return {std::numeric_limits<int>::max(), std::numeric_limits<int>::min(), 0, true};
        }

        NodeProperties left_props = solve(root->left);
        NodeProperties right_props = solve(root->right);

        NodeProperties current_props;
        current_props.size = 0;
        current_props.is_bst = false;

        if (left_props.is_bst && right_props.is_bst &&
            root->data > left_props.max_val &&
            root->data < right_props.min_val) {

            current_props.is_bst = true;
            current_props.size = 1 + left_props.size + right_props.size;
            current_props.min_val = std::min(root->data, left_props.min_val);
            current_props.max_val = std::max(root->data, right_props.max_val);

            max_bst_size = std::max(max_bst_size, current_props.size);
        } else {
            current_props.is_bst = false;
            current_props.min_val = std::numeric_limits<int>::min();
            current_props.max_val = std::numeric_limits<int>::max();
            current_props.size = 0;
        }

        return current_props;
    }

    int largestBst(Node *root) {
        max_bst_size = 0;
        solve(root);
        return max_bst_size;
    }
};


//Approach 1 - Brute force

// class Solution {
// public:
//     bool isBST(Node* node, long long min_val, long long max_val) {
//         if (node == nullptr) {
//             return true;
//         }
//         if (node->data <= min_val || node->data >= max_val) {
//             return false;
//         }
//         return isBST(node->left, min_val, node->data) &&
//               isBST(node->right, node->data, max_val);
//     }

//     int countNodes(Node* node) {
//         if (node == nullptr) {
//             return 0;
//         }
//         return 1 + countNodes(node->left) + countNodes(node->right);
//     }

//     int largestBst(Node *root) {
//         int max_size = 0;
//         if (root == nullptr) {
//             return 0;
//         }

//         std::queue<Node*> q;
//         q.push(root);

//         while (!q.empty()) {
//             Node* current_node = q.front();
//             q.pop();

//             if (isBST(current_node, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max())) {
//                 int current_subtree_size = countNodes(current_node);
//                 max_size = std::max(max_size, current_subtree_size);
//             }

//             if (current_node->left != nullptr) {
//                 q.push(current_node->left);
//             }
//             if (current_node->right != nullptr) {
//                 q.push(current_node->right);
//             }
//         }
//         return max_size;
//     }
// };