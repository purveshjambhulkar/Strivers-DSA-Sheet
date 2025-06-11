// problem link - https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1


/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void addLeftBoundary(Node* node, vector<int>& res) {
    Node* curr = node->left;
    while (curr) {
        if (!(curr->left == NULL && curr->right == NULL))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaves(Node* node, vector<int>& res) {
    if (!node) return;
    if (!node->left && !node->right) {
        res.push_back(node->data);
        return;
    }
    addLeaves(node->left, res);
    addLeaves(node->right, res);
}


void addRightBoundary(Node* node, vector<int>& res) {
    Node* curr = node->right;
    vector<int> tmp;
    while (curr) {
        if (!(curr->left == NULL && curr->right == NULL))
            tmp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    reverse(tmp.begin(), tmp.end());
    res.insert(res.end(), tmp.begin(), tmp.end());
}


  
 vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;
    if (!(root->left == NULL && root->right == NULL)) 
        res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}

};