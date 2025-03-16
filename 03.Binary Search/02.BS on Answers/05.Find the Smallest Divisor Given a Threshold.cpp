class Solution {
    public:
        int solve(vector<int>& nums, int mid) {
            int ans = 0;
            for (int i : nums) {
                ans += (i + mid - 1) / mid; // integer math trick for ceiling division
            }
            return ans;
        }
    
        int smallestDivisor(vector<int>& nums, int threshold) {
            int left = 1;
            int right = *max_element(nums.begin(), nums.end());
            int ans = -1;
    
            while (left <= right) {
                int mid = left + (right - left) / 2;
    
                int temp = solve(nums, mid);
    
                if (temp <= threshold) { // Ensure we catch the smallest valid divisor
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
    
            return ans;
        }
    };
    