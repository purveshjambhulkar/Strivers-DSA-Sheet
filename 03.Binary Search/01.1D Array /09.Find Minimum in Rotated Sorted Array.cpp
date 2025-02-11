class Solution {
    public:
        int findMin(vector<int>& nums) {
            // Approach - Binary Search (O(log n))
    
            int start = 0;
            int end = nums.size() - 1;
            int low = INT_MAX;
    
            while (start <= end) {
                int mid = start + (end - start) / 2;
    
                // Update the minimum element found so far
                low = min(low, nums[mid]);
    
                // If the left half is sorted, move to the right half
                if (nums[start] <= nums[mid]) {
                    low = min(low, nums[start]);
                    start = mid + 1;
                }
                // If the right half is sorted, move to the left half
                else {
                    low = min(low, nums[mid]);
                    end = mid - 1;
                }
            }
    
            return low;
    
            // // Approach 1 Brute Force (Linear Search) -> o(n)
            // int low = INT_MAX;
            // for(int i :nums){
            //     if(i < low){
            //         low = i;
            //     }
            // }
            // return low;
        }
    };