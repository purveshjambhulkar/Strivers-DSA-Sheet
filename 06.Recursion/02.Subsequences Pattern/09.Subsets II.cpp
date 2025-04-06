class Solution {
    public:
        void subsetUtil(vector<int>& nums, vector<vector<int>>& ans,
                        vector<int>& subset, int index) {
            // Push the current subset to answer
            ans.push_back(subset);
    
            for (int i = index; i < nums.size(); i++) {
                // Skip duplicates
                if (i > index && nums[i] == nums[i - 1]) {
                    continue;
                }
    
                // Include
                subset.push_back(nums[i]);
                subsetUtil(nums, ans, subset, i + 1); // Corrected index
                subset.pop_back();                    // Backtrack
            }
        }
    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> subset;
            sort(nums.begin(), nums.end()); // Sort to handle duplicates
            subsetUtil(nums, ans, subset, 0);
            return ans;
        }
    };