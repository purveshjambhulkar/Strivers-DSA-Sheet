// problem link - https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j >= arr[i - 1])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][sum];
    }
};

// class Solution {
// public:
//     bool isSubsetUtil(int index, int currSum, vector<int>& arr, int target, vector<vector<int>> &dp) {
//         if (currSum == target) return true;
//         if (index == arr.size()) return false;

//         if (dp[inde x][currSum] != -1) return dp[index][currSum];

//         bool include = false;
//         if (currSum + arr[index] <= target)
//             include = isSubsetUtil(index + 1, currSum + arr[index], arr, target, dp);

//         bool exclude = isSubsetUtil(index + 1, currSum, arr, target, dp);

//         return dp[index][currSum] = include || exclude;
//     }

//     bool isSubsetSum(vector<int>& arr, int sum) {
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
//         return isSubsetUtil(0, 0, arr, sum, dp);
//     }
// };
