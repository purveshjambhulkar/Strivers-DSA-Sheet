//Approach 3 - DP - Tabulation

class Solution {
public:

    int uniquePathsUtil(int i , int j , vector<vector<int>> &dp){

        if(i == 0 && j == 0){
            return 1;
        }

        if(i < 0 || j < 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int up = uniquePathsUtil(i -1 , j , dp);
        int left = uniquePathsUtil(i , j-1 , dp);

        return dp[i][j] = up + left;

    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m ,vector<int>(n , -1));
        return uniquePathsUtil(m - 1 , n-1, dp);

    }
};
// //Approach 2 - DP - Memoization

// class Solution {
// public:

//     int uniquePathsUtil(int i , int j , vector<vector<int>> &dp){

//         if(i == 0 && j == 0){
//             return 1;
//         }

//         if(i < 0 || j < 0){
//             return 0;
//         }

//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }

//         int up = uniquePathsUtil(i -1 , j , dp);
//         int left = uniquePathsUtil(i , j-1 , dp);

//         return dp[i][j] = up + left;

//     }


//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m ,vector<int>(n , -1));
//         return uniquePathsUtil(m - 1 , n-1, dp);

//     }
// };

//Approach 1 - Normal recursion

// class Solution {
// public:

//     int uniquePathsUtil(int i , int j){

//         if(i == 0 && j == 0){
//             return 1;
//         }

//         if(i < 0 || j < 0){
//             return 0;
//         }

//         int up = uniquePathsUtil(i -1 , j);
//         int left = uniquePathsUtil(i , j-1);

//         return up + left;

//     }


//     int uniquePaths(int m, int n) {
        
//         return uniquePathsUtil(m - 1 , n-1);

//     }
// };