class Solution {
    public:
        void combinationSumUtil(vector<int>& candidates, int target,
                                vector<vector<int>>& ans, vector<int> subset,
                                int index, int sum) {
            // base case
            if (sum > target) {
                return;
            }
            if (sum == target) {
                ans.push_back(subset);
                return;
            }
            if (index == candidates.size()) {
                return;
            }
    
            // include
            if (candidates[index] <= target) {
                subset.push_back(candidates[index]);
                combinationSumUtil(candidates, target, ans, subset, index,
                                   sum + candidates[index]);
                subset.pop_back(); // backtrack
            }
    
            // exclude
            combinationSumUtil(candidates, target, ans, subset, index + 1, sum);
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> subset;
    
            combinationSumUtil(candidates, target, ans, subset, 0, 0);
    
            return ans;
        }
    };
    