// problem link - https://www.geeksforgeeks.org/problems/burning-tree/1


/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void markParent(Node* root , int target ,unordered_map<Node* , Node*> &parent_map  ,Node* &start){
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
           
            
            for(int i = 0 ; i < size ; i++){
                Node* temp = q.front();
                q.pop();
                 if(temp->data == target){
                start = temp;
            }
                
                if(temp->left){
                    parent_map[temp->left] = temp;
                    q.push(temp->left);
                }
                
                if(temp->right){
                    parent_map[temp->right] = temp;
                    q.push(temp->right);
                }
            }
            
        }
        
    }
  
    int minTime(Node* root, int target) {
        // code here
        
        
        //steps
        //first level order traversal and find parent_mapping an
        // and the target node as well
        
        //second traversal from the target node to all the other nodes
        //while q.empty() 
        //maintain time var which increments by 1 after each loop iteration
        
        
        unordered_map<Node* , Node*> parent_map;
        Node* start ; 
        markParent(root , target, parent_map , start);
        
        
        queue<Node* > q;
        int t = 0;
        q.push(start);
        unordered_map<Node* , bool> visited;
        visited[start] = true;
        
        while(!q.empty()){
            int size = q.size();
            t++;
            
            for(int i = 0 ; i < size ; i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parent_map[temp] && !visited[parent_map[temp]]){
                    q.push(parent_map[temp]);
                    visited[parent_map[temp]] = true;                }
            
            }
            
            
        }
        
        
        return t -1;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};