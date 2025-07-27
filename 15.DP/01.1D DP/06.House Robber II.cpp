//proble, link - https://leetcode.com/problems/house-robber-ii

// Approach 4 - Space Optimization

class Solution {
public:
    int robUtil(vector<int> &nums , int startIndex , int endIndex) {

        int prev2 = 0;
        int prev = nums[startIndex];

        for (int i = startIndex + 1; i <= endIndex; i++) {

           int rob = nums[i] + prev2;

            int skip = prev ;
            
            prev2 = prev;
            prev = max(rob, skip);
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int first = robUtil(nums, 0, n - 2);  
        int last = robUtil(nums, 1, n - 1);   

        return max(first, last);
    }
};
// // Approach 3 - Tabulation

// class Solution {
// public:
//     int robUtil(vector<int> &nums , int startIndex , int endIndex) {

//         vector<int> dp(nums.size(), 0);
//         dp[startIndex] = nums[startIndex];

//         for (int i = startIndex + 1; i <= endIndex; i++) {

//             int rob = nums[i];
//             if (i > startIndex + 1) {
//                 rob += dp[i - 2];
//             }

//             int skip = dp[i - 1];

//             dp[i] = max(rob, skip);
//         }

//         return dp[endIndex];
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1)
//             return nums[0];

//         int first = robUtil(nums, 0, n - 2);  
//         int last = robUtil(nums, 1, n - 1);   

//         return max(first, last);
//     }
// };

// //Approach 2 - Memoization

// class Solution {
// public:
//     int robUtil(vector<int>& nums, int startIndex, int endIndex ,
//     vector<int>&dp) {
//         if (startIndex < endIndex) {
//             return 0;
//         }

//         if(dp[startIndex] != -1){
//             return dp[startIndex];
//         }

//         int rob = nums[startIndex] + robUtil(nums, startIndex - 2,
//         endIndex,dp); int skip = robUtil(nums, startIndex - 1, endIndex,dp);

//         dp[startIndex] =  max(rob, skip);
//         return dp[startIndex];
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];

//         vector<int> dp1(n , -1);
//         vector<int> dp2(n , -1);

//         int first = robUtil(nums, n - 2, 0 , dp1);
//         int last = robUtil(nums, n - 1, 1 , dp2);

//         return max(first, last);
//     }
// };

// Approach 1 - Normal Recursion

// class Solution {
// public:
//     int robUtil(vector<int>& nums, int startIndex, int endIndex) {
//         if (startIndex < endIndex) {
//             return 0;
//         }

//         int rob = nums[startIndex] + robUtil(nums, startIndex - 2, endIndex);
//         int skip = robUtil(nums, startIndex - 1, endIndex);

//         return max(rob, skip);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];

//         int first = robUtil(nums, n - 2, 0);
//         int last = robUtil(nums, n - 1, 1);

//         return max(first, last);
//     }
// };
