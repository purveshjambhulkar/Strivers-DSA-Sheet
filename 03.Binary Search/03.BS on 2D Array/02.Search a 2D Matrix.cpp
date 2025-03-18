class Solution {
    public:
        // bool binarySearch(vector<int> arr, int target) {
        //     int left = 0;
        //     int right = arr.size() - 1;
    
        //     while (left <= right) {
        //         int mid = left + (right - left) / 2;
    
        //         if (arr[mid] == target) {
        //             return true;
        //         } else if (arr[mid] > target) {
        //             right = mid - 1;
        //         } else {
        //             left = mid + 1;
        //         }
        //     }
    
        //     return false;
        // }
    
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    
            //Approach 3 - More optimization
            // In a flattened 2d array where 2d array can be treated as 1d array the coordinates of current element are
            // row = index / matrix[0].size()
            // col = index % matrix[0].size()
    
            int size = matrix.size() * matrix[0].size();
    
            int left = 0 ; 
            int  right = size - 1;
    
            while(left <= right){
                int mid = left + (right - left) /2;
    
                int row = mid/matrix[0].size();
                int col = mid%matrix[0].size();
                int ele = matrix[row][col];
                if(ele == target){
                    return true;
                }else if (ele > target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return false;
    
            // // Approach 2 - using binary search
            // for (int i = 0; i < matrix.size(); i++) {
            //     if (matrix[i].front() <= target && matrix[i].back() >= target) {
            //         // Apply Binary search
            //         return binarySearch(matrix[i], target);
            //     }
            // }
    
            // return false;
    
            // Approach 1 - Brute Force - Linear Traversal
    
            // for (int i = 0; i < matrix.size(); i++) {
            //     for (int j = 0; j < matrix[i].size(); j++) {
            //         if (matrix[i][j] == target) {
            //             return true;
            //         }
            //     }
            // }
            // return false;
        }
    };