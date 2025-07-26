// problem link - https://leetcode.com/problems/climbing-stairs/description


// Approach 2 - Memoization

class Solution {
public:
    int climbStairsUtil(int n, vector<int>& memo) {

        if (n == 0) {
            return 1;
        }

        if (n == 1) {
            return 1;
        }

        if (memo[n] != -1) {
            return memo[n];
        }

        int oneStep = climbStairsUtil(n - 1 , memo);
        int twoStep = climbStairsUtil(n - 2 , memo);

        memo[n] = oneStep + twoStep;
        return memo[n];
    }

    int climbStairs(int n) {
        vector<int> memo(n+1 , -1);
        return climbStairsUtil(n , memo);

    }
};

// Approach 1 - Normal Recursion - TLE

// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n == 0){
//             return 1;
//         }

//         if(n == 1){
//             return 1;
//         }

//         int oneStep = climbStairs(n-1);
//         int twoStep = climbStairs(n-2);

//         return oneStep + twoStep;

//     }

// };