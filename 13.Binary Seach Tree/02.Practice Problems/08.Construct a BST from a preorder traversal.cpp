/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* xreate(TreeNode*& root, int d) {
        if (root == NULL) {
            root = new TreeNode(d);
            return root;
        }

        if (root->val > d) {
            root->left = xreate(root->left, d);
        } else {
            root->right = xreate(root->right, d);
        }

        return root;
    }

    TreeNode* buildFromInPre(vector<int>& inorder, int inStart, int inEnd,
                             vector<int>& preorder, int preStart, int preEnd,
                             unordered_map<int, int> inMap) {

            if(inStart > inEnd || preStart > preEnd){
                return nullptr;
            } 

            int temp = preorder[preStart];
            TreeNode* root = new TreeNode(temp);

            int inRoot = inMap[temp];
            int numLeft = inRoot - inStart;


            root->left = buildFromInPre(inorder ,inStart ,inRoot - 1,preorder , preStart + 1, preStart + numLeft , inMap);

            root->right = buildFromInPre(inorder , inRoot +1 , inEnd , preorder , preStart + numLeft + 1  , preEnd  ,inMap);

            return root; 

            
                             }

    TreeNode* buildOptimal(vector<int> &preorder , int &index , int upperBound){

        //base case 
        if(index == preorder.size() || preorder[index] > upperBound){
            return NULL;
        }

        int temp =preorder[index++];
        TreeNode* root = new TreeNode(temp);

        root->left = buildOptimal(preorder , index,temp);
        root->right = buildOptimal(preorder, index , upperBound);

        return root;


    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        // Approach 1 - O(N*N)

        // TreeNode* root = NULL;

        // for(int i : preorder){
        //     xreate(root , i);
        // }

        // return root;

        // Approach 2 - using inorder as well

    //     vector<int> inorder = preorder;
    //     sort(inorder.begin(), inorder.end());
    //     unordered_map<int, int> inMap;

    //     for (int i = 0; i < inorder.size(); i++) {
    //         inMap[inorder[i]] = i;
    //     }

    //     return buildFromInPre(inorder, 0, inorder.size() - 1, preorder, 0,
    //                           preorder.size() - 1, inMap);
    // 


        //Approach 3 - Optimal Solution - O(3N)
        int index = 0;
        return buildOptimal(preorder , index , INT_MAX);

    }



};