// link - https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int leftChild(int i) {
        return 2 * i + 1;
    }
    
    int rightChild(int i) {
        return 2 * i + 2;
    }    
    
    void heapifyDown(vector<int> &arr, int i, int N) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < N && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < N && arr[right] > arr[largest]) {
            largest = right;
        }
        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(arr, largest, N);
        }
    }
  
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        // Start from the last non-leaf node and heapify down each node
        for (int i = N / 2 - 1; i >= 0; i--) {
            heapifyDown(arr, i, N);
        }
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
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends