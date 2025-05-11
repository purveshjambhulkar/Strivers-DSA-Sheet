// link - https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        
        if(arr.size() <= 1){
            return 0;
        }
        
        priority_queue<int , vector<int> , greater<int>> minHeap;
        
        for(int i : arr){
            minHeap.push(i);
        }
        
        int cost = 0;
        
        while(minHeap.size() != 1){
            int rope1 = minHeap.top();
            minHeap.pop();
            int rope2 = minHeap.top();
            minHeap.pop();
            
            cost += rope1 + rope2;
            
            minHeap.push(rope1 + rope2);
            
        }
        
        return cost;
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends