class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
    
    
            // Approach 2 -> 2 ptr + sliding window (eliminating inner loop)
    
            int n = nums.size();
    
            int left = 0;
            int right = 0;
    
            int count = 0;
            int max_len = 0;
    
            while (right < n) {
                if (nums[right] == 0) {
                    count++;
                }
    
                if(count > k ){
                    if(nums[left] == 0){
                        count--;
                    }
                    left++;
                }
                
                if(count <= k){
                    max_len = max(max_len , right - left + 1);
                }
    
    
                right++;
            }
    
            return max_len;
    
    
    
    
            //Approach 1 - 2 ptr + sliding window
    
            // int n = nums.size();
    
            // int left = 0;
            // int right = 0;
    
            // int count = 0;
            // int max_len = 0;
    
            // while (right < n) {
            //     if (nums[right] == 0) {
            //         count++;
            //     }
    
            //     if (count <= k) {
            //         max_len = max(max_len, right - left + 1);
            //     } else {
            //         while (nums[left] != 0) {
            //             left++;
            //         }
            //         left++;
            //         count--;
            //     }
    
            //     right++;
            // }
    
            // return max_len;
        }
    };