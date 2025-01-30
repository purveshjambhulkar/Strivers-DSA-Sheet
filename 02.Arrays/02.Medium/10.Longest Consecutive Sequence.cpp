class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Approach 2 - using set ds

        int n = nums.size();
        if (!n) {
            return 0;
        }
        int longest = 1;
        unordered_set<int> my_set(nums.begin(), nums.end());

        for(auto it : my_set){
            //if curr ele is the beginnig ele
            if(my_set.find(it-1) == my_set.end()){
                int count = 1;
                int x = it;
                while(my_set.find(x+1) != my_set.end()){
                    count++;
                    x++;
                }
                longest = max(longest, count);
            }
        }
        return longest;

        // Approach 1 - Brute Force
        // if (nums.size() == 0) {
        //     return 0;
        // }

        // if (nums.size() == 1) {
        //     return 1;
        // }

        // // Sort the array
        // sort(nums.begin(), nums.end());

        // int max_cons = 1; // Initialize to 1 since a single element is a
        // sequence of length 1 int ans = 1;      // Initialize ans to 1

        // for (int i = 1; i < nums.size(); i++) {
        //     // Skip duplicates
        //     if (nums[i] == nums[i - 1]) {
        //         continue;
        //     }

        //     // Check if the current number forms a consecutive sequence
        //     if (nums[i] - nums[i - 1] == 1) {
        //         max_cons++; // Increment the current sequence length
        //         ans = max(ans, max_cons); // Update the maximum sequence
        //         length
        //     } else {
        //         max_cons = 1; // Reset the current sequence length
        //     }
        // }

        // return ans;
    }
};