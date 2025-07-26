problem link - https://leetcode.com/problems/fibonacci-number/description


// DP - Tabulation + Space Optimization

class Solution {
public:
    int fib(int n) {

        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        int x = 0;
        int y = 1;


        for(int i = 2 ; i <= n ;i++){
            int next = x + y;
            x = y;
            y = next;
        }

        return y;


        
    }
};
// DP - Tabulation

// class Solution {
// public:
//     int fib(int n) {

//         if (n == 0) {
//             return 0;
//         }
//         if (n == 1) {
//             return 1;
//         }
//         vector<int> memo(n + 1, 0);
//         memo[0] = 0;
//         memo[1] = 1;


//         for(int i = 2 ; i <= n ;i++){
//             memo[i] = memo[i-1] + memo[i-2];
//         }

//         return memo[n];

        
//     }
// };
// // DP - Memoization

// class Solution {
// public:
//     int fibUtil(int n, vector<int>& memo) {

//         if (n == 0) {
//             return 0;
//         }

//         if (n == 1) {
//             return 1;
//         }

//         if (memo[n] != -1) {
//             return memo[n];
//         }

//         memo[n] = fibUtil(n - 1, memo) + fibUtil(n - 2, memo);
//         return memo[n];
//     }

//     int fib(int n) {
//         vector<int> memo(n + 1, -1);

//         return fibUtil(n, memo);
//     }
// };

// NORMAL RECURSION

// class Solution {
// public:
//     int fib(int n) {
//         if(n == 0){
//             return 0;
//         }

//         if(n == 1){
//             return 1;
//         }

//         return fib(n-1) + fib(n-2);
//     }
// };