class Solution {
    public:
    
        void createSubsets(vector<vector<int>> &ans ,vector<int> &subset , int index , vector<int>& nums ){
            //base case
            if(index == nums.size()){
                ans.push_back(subset);
                return;
            }
    
            //include
            subset.push_back(nums[index]);
            createSubsets(ans , subset , index + 1 , nums);
    
            //exclude
            subset.pop_back();
            createSubsets(ans , subset , index + 1 , nums);
    
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            //Recursive Approach
    
            vector<vector<int>> ans;
            vector<int> subset;
    
            createSubsets(ans , subset , 0 , nums);
            return ans;
    
    
    
    
            // vector<vector<int>> ans;
            // int n = nums.size();
    
            // // Start with empty subset
            // ans.push_back({});
    
            // for (int i = 0; i < n; i++) {
            //     int size = ans.size();
    
            //     // Add nums[i] to all existing subsets
            //     for (int j = 0; j < size; j++) {
            //         vector<int> temp = ans[j]; // Copy an existing subset
            //         temp.push_back(nums[i]);   // Add current element
            //         ans.push_back(temp);       // Add new subset to result
            //     }
            // }
    
            // return ans;
        }
    };
    