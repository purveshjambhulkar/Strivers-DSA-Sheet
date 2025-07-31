//Approach 2 - Memoization

class Solution {
public:
    bool util(vector<int>& nums, int target, int index, int currSum,vector<vector<int>> &dp) {

        if (currSum == target) {
            return true;
        }

        if (index == nums.size()) {
            return false;
        }

        if(dp[index][currSum] != -1){
            return dp[index][currSum];
        }

        bool include = false;
        if (currSum + nums[index] <= target) {
            include = util(nums, target, index + 1, currSum + nums[index] , dp);
        }

        bool exclude = util(nums, target, index + 1, currSum , dp);

        return dp[index][currSum] =  include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) {
            return false;
        }
        sum = sum / 2;

        vector<vector<int>> dp(nums.size() , vector<int>(sum+1 , -1));

        return util(nums, sum, 0, 0 , dp);
    }
};

//Approach 1 - Normal Recursion

// class Solution {
// public:
//     bool util(vector<int>& nums, int target, int index, int currSum) {

//         if (currSum == target) {
//             return true;
//         }

//         if (index == nums.size()) {
//             return false;
//         }

//         bool include = false;
//         if (currSum + nums[index] <= target) {
//             include = util(nums, target, index + 1, currSum + nums[index]);
//         }

//         bool exclude = util(nums, target, index + 1, currSum);

//         return include || exclude;
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);

//         if (sum % 2 != 0) {
//             return false;
//         }
//         sum = sum / 2;

//         return util(nums, sum, 0, 0);
//     }
// };