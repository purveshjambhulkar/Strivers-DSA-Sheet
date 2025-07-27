// Approach 4 - Space optimization

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        
        int prev2 = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int rob = nums[i] + prev2;

            int skip = prev ;
            
            prev2 = prev;
            prev = max(rob, skip);
        }


        return prev;
    }
};
// // Approach 3 - Tabulation

// class Solution {
// public:
//     int rob(vector<int>& nums) {

//         vector<int> dp(nums.size(), 0);
//         dp[0] = nums[0];

//         for (int i = 1; i < nums.size(); i++) {

//             int rob = nums[i];
//             if (i > 1) {
//                 rob += dp[i - 2];
//             }

//             int skip = dp[i - 1];

//             dp[i] = max(rob, skip);
//         }


//         return dp[nums.size() - 1];
//     }
// };
// // Approach 2 - Memoization

// class Solution {
// public:
//     int robUtil(vector<int>& nums, int index , vector<int> &dp) {

//         if (index == 0) {
//             return nums[index];
//         }

//         if (index < 0) {
//             return 0;
//         }

//         if(dp[index] != -1){
//             return dp[index];
//         }

//         int rob = nums[index] + robUtil(nums, index - 2 , dp);

//         int skip = robUtil(nums, index - 1 , dp);

//         dp[index] =  max(rob, skip);
//         return dp[index];
//     }

//     int rob(vector<int>& nums) {

//         vector<int> dp(nums.size(), -1);

//         return robUtil(nums, nums.size() - 1, dp);
//     }
// };

// Approach 1 - Normal recursion - TLE

// class Solution {
// public:
//     int robUtil(vector<int>& nums, int index) {

//         if (index == 0) {
//             return nums[index];
//         }

//         if (index < 0) {
//             return 0;
//         }

//         int rob = nums[index] + robUtil(nums, index - 2);

//         int skip = robUtil(nums, index - 1);

//         return max(rob, skip);
//     }

//     int rob(vector<int>& nums) { return robUtil(nums, nums.size() - 1); }
// };