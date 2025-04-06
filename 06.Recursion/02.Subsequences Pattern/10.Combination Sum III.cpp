class Solution {
    public:
        void combiUtil(int k, int n, vector<int>& util, vector<vector<int>>& ans,
                       vector<int> subset, int index, int temp) {
            // base case
            if (temp == n && subset.size() == k) {
                ans.push_back(subset);
                return;
            }
    
            if (index == util.size()) {
                return;
            }
    
            if (subset.size() > k) {
                return;
            }
    
            // include call
            subset.push_back(util[index]);
            combiUtil(k, n, util, ans, subset, index + 1, temp + util[index]);
    
            // exclude call
            subset.pop_back();
            combiUtil(k, n, util, ans, subset, index + 1, temp);
        }
    
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<int> util;
            for (int i = 1; i <= 9; i++) {
                util.push_back(i);
            }
    
            vector<vector<int>> ans;
            vector<int> subset;
            combiUtil(k, n, util, ans, subset, 0, 0);
            return ans;
        }
    };