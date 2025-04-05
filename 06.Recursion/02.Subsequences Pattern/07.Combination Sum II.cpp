class Solution {
    public:
        void combinationSumUtil(vector<int>& candidates, int target,
                                vector<vector<int>>& ans, vector<int>& subset,
                                int index, int sum) {
            // base case
            if (sum == target) {
                ans.push_back(subset);
                return;
            }
    
            for (int i = index; i < candidates.size(); i++) {
                // Skip duplicates
                if (i > index && candidates[i] == candidates[i - 1]) {
                    continue;
                }
    
                if (candidates[i] > target - sum) {
                    break; // No need to continue if the candidate exceeds the remaining sum
                }
    
                // Include the current element
                subset.push_back(candidates[i]);
                combinationSumUtil(candidates, target, ans, subset, i + 1, sum + candidates[i]);
                subset.pop_back(); // Backtrack
            }
        }
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> subset;
            sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
            combinationSumUtil(candidates, target, ans, subset, 0, 0);
            return ans;
        }
    };
    