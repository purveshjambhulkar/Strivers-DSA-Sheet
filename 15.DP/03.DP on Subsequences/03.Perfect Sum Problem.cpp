// problem link - https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1



//Approach 2 - Dp - Memoization

class Solution {
  public:
  
    int perfectUtil(vector<int>& arr , int target , int index , int currSum ,vector<vector<int>> &dp){
        
        //base case
        if(index == arr.size()){
            if(currSum == target){
                return 1;
            }else{
                return 0;
            }    
        }
        
        if(dp[index][currSum] != -1){
            return dp[index][currSum];
        }
        
        
        int include = 0;
        if(currSum + arr[index] <= target){
            include = perfectUtil(arr , target , index+1 , currSum + arr[index] , dp);
        }
        
        int exclude = perfectUtil(arr, target , index +1 ,currSum , dp);
        
        return dp[index][currSum] =  include + exclude;
        
        
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        
        vector<vector<int>> dp(arr.size() , vector<int>(target+1 , -1));
        return perfectUtil(arr , target , 0  ,0 , dp);
        
        
    }
};

//Approach 1 - Normal Recursion


// class Solution {
//   public:
  
//     int perfectUtil(vector<int>& arr , int target , int index , int currSum){
        
//         //base case
//         if(index == arr.size()){
//             if(currSum == target){
//                 return 1;
//             }else{
//                 return 0;
//             }    
//         }
        
        
//         int include = 0;
//         if(currSum + arr[index] <= target){
//             include = perfectUtil(arr , target , index+1 , currSum + arr[index]);
//         }
        
//         int exclude = perfectUtil(arr, target , index +1 ,currSum);
        
//         return include + exclude;
        
        
//     }
  
//     int perfectSum(vector<int>& arr, int target) {
//         // code here
        
        
//         return perfectUtil(arr , target , 0  ,0);
        
        
//     }
// };