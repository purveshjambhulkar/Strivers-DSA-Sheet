//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        //algo- find min and swap
        
        int n = arr.size();
        for(int i = 0; i <= n-2; i++){
            int minIndex = i;
            for(int j = i+1; j <=n-1; j++){
                if(arr[j] < arr[minIndex]){
                    minIndex = j;
                } 
            }
            
            swap(arr[i] , arr[minIndex]);
            // int temp = arr[i];
            // arr[i] = arr[minIndex];
            // arr[minIndex] =temp;
        }
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        obj.selectionSort(a);

        Array::print(a);
        cout << "~" << endl;
    }
}

// } Driver Code Ends