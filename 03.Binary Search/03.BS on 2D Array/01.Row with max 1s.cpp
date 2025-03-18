//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
  
    int countOnes(vector<int> arr){
        int left = 0 ;
        int right= arr.size() -1;
        int firstOccur = arr.size();
        
        while(left <= right){
            int mid = left + (right - left) /2;
            
            if(arr[mid] == 1){
                firstOccur = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return arr.size() - firstOccur;
         
    }
  
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        //Approach 2 - calculating the number of ones 
        // using binary search
        int row = -1;
        int count = 0;
        
        for(int i = 0 ; i < arr.size(); i++){
            int temp = countOnes(arr[i]);
            if(temp > count){
                count = temp;
                row = i;
            }
        }
        return row;
        
        
        
        //Approach 1 - sum and compare 
        // int row = -1;
        // int sum = 0;
        
        // for(int i = 0 ; i < arr.size(); i++){
        //     if(accumulate(arr[i].begin() , arr[i].end() , 0) > sum){
        //         sum = accumulate(arr[i].begin() , arr[i].end() ,0);
        //         row = i;
        //     }    
        // }
        // return row;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends