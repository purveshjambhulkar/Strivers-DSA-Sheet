class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
    
            // Approach 2 - Binary Search -> O(log n)
    
            int start = 0;
            int end = nums.size() - 1;
    
            while (start <
                   end) { // Use '<' instead of '<=' to prevent infinite loop
                int mid = start + (end - start) / 2;
    
                // Ensure mid is even so we always compare pairs correctly
                if (mid % 2 == 1) {
                    mid--; // Move mid to even index
                }
    
                // If mid and mid+1 form a valid pair, single element is on the
                // right side
                if (nums[mid] == nums[mid + 1]) {
                    start = mid + 2;
                } else {
                    end = mid; // Single element is on the left side (including mid)
                }
            }
    
            return nums[start];
    
            // Approach 1 - Brute force (XOR)
    
            // int XOR = nums[0] ;
            // for(int i = 1 ; i < nums.size() ;i++){
            //     XOR ^= nums[i];
            // }
    
            // return XOR;
        }
    };