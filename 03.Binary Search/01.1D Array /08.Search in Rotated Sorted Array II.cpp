class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int start = 0;
            int end = nums.size() - 1;
    
            while (start <= end) {
                int mid = start + (end - start) / 2;
    
                // Found target
                if (nums[mid] == target) {
                    return true;
                }
    
                // Handle duplicate case by shrinking search space
                if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                    start++;
                    end--;
                    continue;
                }
    
                // Check if the left half is sorted
                if (nums[start] <= nums[mid]) {
                    if (nums[start] <= target && target < nums[mid]) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
                // Right half is sorted
                else {
                    if (nums[mid] < target && target <= nums[end]) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }
            return false;
        }
    };