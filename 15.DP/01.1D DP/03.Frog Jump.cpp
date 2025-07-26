// problem link - https://www.geeksforgeeks.org/problems/geek-jump/1

//Approach 4 - Space Optimization

class Solution {
  public:
  
    int minCost(vector<int>& height) {
        
        int n = height.size();
        if(n == 0){
            return 0;
        }
        
        if(n == 1){
            return 0;
        }
        
        
        
        int x = 0;
        int y = abs(height[0] - height[1]);
        
        for(int i = 2 ; i < n ;i++){
            int oneJump = y + abs(height[i] - height[i-1]);
            
            int twoJump = x + abs(height[i] - height[i-2]);
            
            x=y;
            y = min(oneJump , twoJump);
        }
        
        
        return y;
        
        
        
    }
};
// //Approach 3 - Tabulation

// class Solution {
//   public:
  
//     int minCost(vector<int>& height) {
        
//         int n = height.size();
//         if(n == 0){
//             return 0;
//         }
        
//         if(n == 1){
//             return 0;
//         }
        
//         vector<int> dp(n , -1);
        
//         dp[0] = 0;
//         dp[1] = abs(height[0] - height[1]);
        
//         for(int i = 2 ; i < n ;i++){
//             int oneJump = dp[i-1] + abs(height[i] - height[i-1]);
            
//             int twoJump = dp[i-2] + abs(height[i] - height[i-2]);
            
//             dp[i] = min(oneJump , twoJump);
//         }
        
        
//         return dp[n-1];
        
        
        
//     }
// };


// //Approach 2 - Memoization

// class Solution {
//   public:
  
//     int minCostUtil(int n , vector<int>& height , vector<int>& memo){
        
//         if(n == 0){
//             return 0;
//         }
        
//         if(memo[n] != -1){
//             return memo[n];
//         }
        
//         int left = minCostUtil(n-1 , height , memo) + abs(height[n] - height[n-1]);
        
//         int right = INT_MAX;
//         if(n > 1){
//             right = minCostUtil(n-2, height , memo) + abs(height[n] - height[n-2]);
//         }
        
//         memo[n] =  min(left , right);
//         return memo[n];
//     }
  
//     int minCost(vector<int>& height) {
//         // Code here
//         int n = height.size() -1 ;
//         vector<int> memo(n + 1 , -1);
//         return minCostUtil(n , height ,memo );
        
//     }
// };

//Approach 1 - Normal Recursion - TLE

// class Solution {
//   public:
  
//     int minCostUtil(int n , vector<int>& height){
        
//         if(n == 0){
//             return 0;
//         }
        
//         int left = minCostUtil(n-1 , height) + abs(height[n] - height[n-1]);
        
//         int right = INT_MAX;
//         if(n > 1){
//             right = minCostUtil(n-2, height) + abs(height[n] - height[n-2]);
//         }
        
//         return min(left , right);
//     }
  
//     int minCost(vector<int>& height) {
//         // Code here
//         int n = height.size() -1 ;
//         return minCostUtil(n , height);
        
//     }
// };