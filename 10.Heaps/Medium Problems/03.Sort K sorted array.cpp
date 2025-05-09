// link - https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        
        priority_queue<int , vector<int> , greater<int>> minHeap;
        int i ;
        int j;
        for(i = 0; i < k +1; i++){
            minHeap.push(arr[i]);
        }
        
        for( j = 0 ; i < arr.size() ; j++ , i++){
            arr[j] = minHeap.top();
            minHeap.pop();
            
            minHeap.push(arr[i]);
        }
        
        while(!minHeap.empty()){
            arr[j] = minHeap.top();
            minHeap.pop();
            j++;
        }
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends