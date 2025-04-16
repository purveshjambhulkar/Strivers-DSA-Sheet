vector<int> Solution::prevSmaller(vector<int> &A) {
    
    //Approach 2 - Stacks
    
    int n = A.size();
    vector<int> ans(A.size() , -1);
    stack<int> st;
    
    for(int i = 0 ; i < n ; i++){
        
        while(!st.empty() && st.top() >= A[i]){
            st.pop();
        }
        
        if(st.empty()){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }
        
        st.push(A[i]);
    }
    
    return ans;
    
    
    
    
    //Approach 1  - Loops and mapping
    
    // int n = A.size();
    // vector<int> ans(A.size() , -1);
    
    // for(int i = n - 1 ; i >= 0 ; i--){
        
    //     int num = A[i];
        
    //     for(int j = i - 1 ; j >=0 ; j--){
            
    //         if(A[j] < num){
    //             ans[i] = A[j];
    //             break;
    //         }
            
    //     }
    // }
    
    // return ans;
     
    
}
