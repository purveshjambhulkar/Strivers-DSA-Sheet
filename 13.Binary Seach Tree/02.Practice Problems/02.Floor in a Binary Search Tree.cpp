// Problem link - https://www.geeksforgeeks.org/problems/floor-in-bst/1


// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        
        int ans = -1;
        
        while(root){
            int temp = root->data;
            
            if(temp <= x){
                ans = temp;
            }
            
            if(temp > x){
                root = root->left;
            }else{
                root = root->right;
            }
            
        }
        
        return ans;
        
        
        
        
        
    }
};