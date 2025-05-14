// link - https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1


//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        
        for (int i = 0; i < n; ++i) {
            jobs.emplace_back(profit[i], deadline[i]);
        }
        
        // Sort jobs in descending order of profit
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<bool> slots(maxDeadline + 1, false); // slots[0] is unused
        
        int count = 0;
        int totalProfit = 0;
        
        for (const auto &job : jobs) {
            int currentProfit = job.first;
            int currentDeadline = job.second;
            
            // Find the latest available slot before the deadline
            for (int i = currentDeadline; i >= 1; --i) {
                if (!slots[i]) {
                    slots[i] = true;
                    count++;
                    totalProfit += currentProfit;
                    break;
                }
            }
        }
        
        return {count, totalProfit};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends   