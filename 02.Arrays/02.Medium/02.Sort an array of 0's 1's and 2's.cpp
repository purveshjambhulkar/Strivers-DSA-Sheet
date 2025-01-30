class Solution {
public:
    void sortColors(vector<int>& nums) {

        // Approach 2 - Dutch National Flag algo
        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;
        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[right]);
                right--;
            }
        }

        // Approach 1 - brute force
        //  vector<int> freq(3, 0);
        //  for(int i : nums){
        //      freq[i]++;
        //  }

        // int ind = 0;
        // for(int i = 0; i < freq[0];i++){
        //     nums[ind++] = 0;
        // }
        // for(int i = 0; i < freq[1];i++){
        //     nums[ind++] = 1;
        // }
        // for(int i = 0; i < freq[2];i++){
        //     nums[ind++] = 2;
        // }

        // violating the rule
        //  sort(nums.begin() , nums.end());
    }
};