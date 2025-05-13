class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        //Approch 2 - Greedy Approach

        int maxReach = 0;
        for(int i = 0; i < nums.size() ;i++){
            if(i > maxReach){
                return false;
            }

            //update maxReach
            maxReach = max(maxReach ,i + nums[i]);
            if(maxReach >= nums.size() - 1){
                return true;
            }
        }
        return true;
    }
};

//Approach 1 - Recursion - TLE

// class Solution {
// public:
//     void jumpUtil(vector<int>& nums, int jump, int index, bool& ans) {
//         if (index == nums.size() - 1) {
//             ans = true;
//             return;
//         }
//         if (index > nums.size() - 1) {
//             return;
//         }
//         int jumps = nums[index];
//         if (nums[index] == 0) {
//             return;
//         }

//         // recursive calls
//         while (jumps >= 1) {
//             if (jumps + index < nums.size()) {
//                 jumpUtil(nums, jumps, index + jumps, ans);
//             }
//             jumps--;
//         }
//     }

//     bool canJump(vector<int>& nums) {
//         bool ans = false;
//         jumpUtil(nums, nums[0], 0, ans);
//         return ans;
//     }
// };