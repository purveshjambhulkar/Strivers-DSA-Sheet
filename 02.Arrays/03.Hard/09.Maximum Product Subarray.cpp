class Solution {
    public:
        int maxProduct(vector<int>& nums) {
           if (nums.empty()) return 0;
    
            int currMax = nums[0];
            int currMin = nums[0];
            int maxProd = nums[0];
    
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < 0) {
                    // Swap currMax and currMin if the current number is negative
                    swap(currMax, currMin);
                }
    
                // Update currMax and currMin
                currMax = max(nums[i], currMax * nums[i]);
                currMin = min(nums[i], currMin * nums[i]);
    
                // Update maxProd
                maxProd = max(maxProd, currMax);
            }
    
            return maxProd;
        }
    };