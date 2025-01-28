//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    void merge(vector<int>& arr , int low , int mid , int high){
        vector<int> temp;
        
        int left = low ; 
        int right =mid  + 1 ;
        
        while (left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }else{
                temp.push_back(arr[right++]);
            }
        }
        
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        
        while(right <= high){
            temp.push_back(arr[right++]);
        }
        
        for(int i = low ; i <= high; i++){
            arr[i] = temp[i - low];
        }
    }
  
    void mergeSort(vector<int>& arr, int low, int high) {
        // code here
        
        //divide and merge
        if(low == high){
            return;
        }
        int mid= (low + high)/2;
        
        mergeSort(arr, low , mid);
        mergeSort(arr , mid+1  , high);
        merge(arr , low , mid , high);
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
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends