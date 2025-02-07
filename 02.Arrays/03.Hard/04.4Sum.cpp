class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Sorting for two-pointer approach
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int first = nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicate first element
                continue;

            for (int j = i + 1; j < n; j++) { // Fix: Start `j` from `i + 1`
                if (j > i + 1 && nums[j] == nums[j - 1]) // Fix: Correct duplicate check
                    continue;

                int second = nums[j];

                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long sum = (long long)first + second + nums[left] + nums[right]; // Prevent overflow
                    if (sum == target) {
                        ans.push_back({first, second, nums[left], nums[right]});

                        // Skip duplicate elements
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    } else if (sum > target) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        return ans;
    }
};
