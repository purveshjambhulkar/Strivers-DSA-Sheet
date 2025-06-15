// problem link - https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1


/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    
    int ans = -1;
    
    while(root){
        int temp = root->data;
        
        if(temp >= input){
            ans = temp;
        }
        
        if(temp < input){
            root = root->right;
        }else{
            root = root->left;
        }
    }
    
    
    return ans;
    
    
    
}