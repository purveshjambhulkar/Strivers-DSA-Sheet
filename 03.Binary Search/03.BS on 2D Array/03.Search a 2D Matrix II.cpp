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
    
            // Approach 3 - Eliminating the row and col
            // If we see the first row and last col, they are in sorted order
            // So we can eliminate the row or col by selecting the mid(right
            // corner(we can take left corner as well)) element for comparision
    
            int row = 0;
            int col = matrix[0].size() -1;
            
            while(row < matrix.size() && col >= 0){
                if(matrix[row][col] == target){
                    return true;
                }else if(matrix[row][col] > target){
                    col--;
                }else{
                    row++;
                }
            }
            return false;
    
    
    
    
            // // Approach 2 - Optimising the seach using Binary search
            // for(int i = 0 ; i < matrix.size() ; i++){
            //     //Bin seach
            //     if(binarySearch(matrix[i] , target)){
            //         return true;
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