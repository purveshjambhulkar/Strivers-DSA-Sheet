// problem link - https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1


// User function template for C++

//Approach 4 - Space Optimization

class Solution {
  public:
    // calculate the maximum sum with out adjacent
    
    int findMaxSum(vector<int>& arr) {
           int n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return arr[0];

    int prev2 = 0;
    int prev = arr[0];

    for(int i = 1; i < n; i++) {
        int pick = arr[i] + prev2;
        int skip = prev;
        int curr = max(pick, skip);

        prev2 = prev;
        prev = curr;
    }

    return prev;
        
        
        
    }
};
// // User function template for C++

// //Approach 3 - Tabulation

// class Solution {
//   public:
//     // calculate the maximum sum with out adjacent
    
//     int findMaxSum(vector<int>& arr) {
//         // code here
        
//         vector<int> tab(arr.size() , 0);
//         tab[0] = arr[0];
        
        
//         for(int i = 1; i < arr.size() ; i++){
            
//             int pick = arr[i];
//             if(i > 1){
//                 pick+=tab[i-2];
//             }
            
//             int skip = tab[i-1];
            
//             tab[i] = max(pick , skip);
            
//         }
        
//         return tab[arr.size() -1];
        
        
        
//     }
// };
// // User function template for C++

// //Approach 2 - Memoization

// class Solution {
//   public:
//     // calculate the maximum sum with out adjacent
    
//     int findMaxUtil(vector<int>&arr , int index , vector<int> &memo){
        
//         if(index == 0){
//             return arr[index];
//         }
        
//         if(index < 0){
//             return 0;
//         }
        
//         if(memo[index] != -1){
//             return memo[index];
//         }
        
        
//         int pick = arr[index] + findMaxUtil(arr , index - 2 , memo);
        
//         int skip = findMaxUtil(arr, index - 1 , memo);
        
//         memo[index] =  max(pick , skip);
//         return memo[index];
        
        
//     }
    
//     int findMaxSum(vector<int>& arr) {
//         // code here
        
//         vector<int> memo(arr.size() , -1);
//         return findMaxUtil(arr , arr.size() - 1 , memo);
        
        
//     }
// };

//Approach 1 - Normal recusion - TLE

// // User function template for C++
// class Solution {
//   public:
//     // calculate the maximum sum with out adjacent
    
//     int findMaxUtil(vector<int>&arr , int index){
        
//         if(index == 0){
//             return arr[index];
//         }
        
//         if(index < 0){
//             return 0;
//         }
        
        
//         int pick = arr[index] + findMaxUtil(arr , index - 2);
        
//         int skip = findMaxUtil(arr, index - 1);
        
//         return max(pick , skip);
        
        
//     }
    
//     int findMaxSum(vector<int>& arr) {
//         // code here
        
        
//         return findMaxUtil(arr , arr.size() - 1);
        
        
//     }
// };