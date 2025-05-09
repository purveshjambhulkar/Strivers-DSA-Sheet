// link - https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int leftChild(int i){
        return(2 * i + 1);
    }
    
    int rightChild(int i){
        return(2 * i + 2);
    }
  
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i = 0 ; i < n ; i++){
            int left = leftChild(i);
            int right = rightChild(i);
            
            if(left >= 0 && left < n && arr[i] < arr[left]){
                return false;
            }
            if(right >= 0 && right < n && arr[i] < arr[right]){
                return false;
            }
            
        }
        
        
        return true;
    }
};


//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends