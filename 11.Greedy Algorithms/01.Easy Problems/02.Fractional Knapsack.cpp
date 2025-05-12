// link - https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
     double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, int>> ratios;
        int n = val.size();
        
        // Calculate value-to-weight ratios
        for (int i = 0; i < n; ++i) {
            double ratio = (double)val[i] / wt[i];
            ratios.push_back({ratio, i});
        }
        
        // Sort items in descending order of their value-to-weight ratio
        sort(ratios.begin(), ratios.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
            return a.first > b.first;
        });
        
        double totalValue = 0.0;
        int remainingCapacity = capacity;
        
        for (const auto& item : ratios) {
            int index = item.second;
            int itemWeight = wt[index];
            int itemValue = val[index];
            
            if (remainingCapacity >= itemWeight) {
                // Take the whole item
                totalValue += itemValue;
                remainingCapacity -= itemWeight;
            } else {
                // Take a fraction of the item
                double fraction = (double)remainingCapacity / itemWeight;
                totalValue += fraction * itemValue;
                remainingCapacity = 0;
                break;
            }
        }
        
        return totalValue;
    }
};









//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends