class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int x= 0;
        for(int i = 0 ;i < size; i++){
            if(nums[i] != 0){
                nums[x++] = nums[i];
            }
        }
        while(x < size){
            nums[x++] = 0;
        }
    }
};