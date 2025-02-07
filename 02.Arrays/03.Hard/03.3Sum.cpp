class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Approach 2 - Modified 2 sum
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            // skip the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int first = nums[i];
            int right = n - 1;
            int left = i + 1;

            while (left < right) {

                // element found
                if (first + nums[left] + nums[right] == 0) {
                    ans.push_back({first, nums[left], nums[right]});

                    // skip duplicates
                    while (left < right &&
                           nums[left] == nums[left + 1]) { // req base case
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;

                } else if (first + nums[left] + nums[right] > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return ans;

        // // Approach 1 - Brute Force
        // int n = nums.size();
        // vector<vector<int>> ans;
        // set<vector<int>> myset;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         for (int k = j + 1; k < n; k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 vector<int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin() , temp.end());
        //                 myset.insert(temp);
        //             }
        //         }
        //     }
        // }

        // for (auto i : myset) {
        //     ans.push_back(i);
        // }

        // return ans;
    }
};