// problem link - https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


// Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        if(!root){
            return {};
        }
        map<int , int> mpp;
        queue<pair<Node* , int>>q;
        q.push({root , 0});
        
        while(!q.empty()){
            Node* temp = q.front().first;
            int level = q.front().second;
            q.pop();
            
            mpp[level] = temp->data;
            
            if(temp->left){
                q.push({temp->left , level - 1});
            }
            
            if(temp->right){
                q.push({temp->right , level + 1});
            }
        }
        
        vector<int> result;
        for(auto it = mpp.begin() ; it != mpp.end() ; it++){
            result.push_back(it->second);
        }
        
        return result;
        
        
    }
};