//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
  
        //Appraoch 1
        int n = arr.size();
        int sum = (n * (n + 1)) / 2;  // Correct formula for sum of first N natural numbers
        int repeat = -1, sumArr = 0;  // Initialize repeat and sumArr properly

        sort(arr.begin(), arr.end()); // Sorting to easily find duplicate

        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) {  // Finding the duplicate element
                repeat = arr[i];
            }
            sumArr += arr[i];
        }

        int missing = sum - (sumArr - repeat);  // Correct formula to find missing number

        return {repeat, missing};
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
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends