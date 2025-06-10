// problem link - https://www.naukri.com/code360/problems/tree-traversal_981269?leftPanelTabValue=SUBMISSION




/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    stack<pair<TreeNode* , int>> st;
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;
    st.push({root , 1});

    while(!st.empty()){
        TreeNode* temp = st.top().first;
        int num = st.top().second;
        st.pop();

        if(num == 1){
            preOrder.push_back(temp->data);
            st.push({temp, ++num});
            if(temp->left){
                st.push({temp->left , 1});
            }
        }else if (num == 2){
            inOrder.push_back(temp->data);
            st.push({temp,++num});
            if(temp->right){
                st.push({temp->right , 1});
            }
        }else{
            postOrder.push_back(temp->data);
            
        }
    }

    return {inOrder , preOrder, postOrder};



}