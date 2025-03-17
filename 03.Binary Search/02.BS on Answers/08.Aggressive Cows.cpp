//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
   int solve(vector<int>& stalls, int k, int mid) {
        int last = stalls[0];  
        int cow = 1;            

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - last >= mid) { 
                cow++;
                last = stalls[i];         
            }
        }

        return cow;
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());  // Ensure sorted stalls
        
        int left = 1;
        int right = stalls.back() - stalls.front();
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int cow = solve(stalls, k, mid);

            if (cow >= k) {   
                ans = mid;    
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends