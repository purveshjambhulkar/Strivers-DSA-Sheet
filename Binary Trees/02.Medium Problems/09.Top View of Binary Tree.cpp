// problem link - https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
   vector<int> topView(Node *root) {
    if (!root) return {};

    map<int, int> mpp; // horizontal distance -> node value
    queue<pair<Node*, int>> q; // node, horizontal distance
    q.push({root, 0});

    while (!q.empty()) {
        Node* node = q.front().first;
int level = q.front().second;

        q.pop();

        if (mpp.find(level) == mpp.end()) {
            mpp[level] = node->data;
        }

        if (node->left) q.push({node->left, level - 1});
        if (node->right) q.push({node->right, level + 1});
    }

    vector<int> result;
   for (auto it = mpp.begin(); it != mpp.end(); ++it) {
    result.push_back(it->second);
}

    return result;
}

};