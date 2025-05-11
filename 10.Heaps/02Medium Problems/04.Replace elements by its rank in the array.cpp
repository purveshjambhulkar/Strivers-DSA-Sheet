// link - https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1


//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        
        //Approach 2 - using mean heap
        
        priority_queue<pair<int ,int> , vector<pair<int ,int>>,greater<pair<int,int>>> minHeap;
        
        for(int i = 0 ; i < arr.size() ; i++){
            minHeap.push({arr[i] , i});
        }
        
        int lastEle= INT_MAX;
        int rank = 0;
        
        while(!minHeap.empty()){
            int curr = minHeap.top().first;
            int index = minHeap.top().second;
            minHeap.pop();
            
            if(lastEle == INT_MAX || lastEle != curr){
                rank++;
            }
            arr[index] = rank; 
            lastEle = curr;
        }
        
        return arr;
        
         //Approah 1 - sorting
    
        // vector<int> arr1;
        // arr1 = arr;
        // sort(arr1.begin() , arr1.end());
        // int rank = 1;
        // unordered_map<int , int> mpp;
        
        
        // for(int i : arr1){
            
        //     if(mpp.find(i) == mpp.end()){
        //         mpp[i] = rank;
        //         rank++;
        //     }
            
        // }
        
        // for(int i = 0 ; i < arr.size(); i++){
        //     arr[i] = mpp[arr[i]];
        // }
        
        // return arr;
      
        
    }
};



//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends