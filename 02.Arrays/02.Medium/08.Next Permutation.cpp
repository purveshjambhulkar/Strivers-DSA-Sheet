class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int br = -1;  // Initialize breakpoint

        // Step 1: Find the breakpoint
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                br = i;
                break;
            }
        }

        // If no breakpoint is found, reverse the array and return
        if (br == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the next larger element
        for (int i = n - 1; i > br; i--) {
            if (nums[i] > nums[br]) {
                swap(nums[i], nums[br]);
                break;
            }
        }

        // Step 3: Reverse the subarray after the breakpoint
        reverse(nums.begin() + br + 1, nums.end());
    }
};