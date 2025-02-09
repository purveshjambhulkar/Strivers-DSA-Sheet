class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int right = n -1 ;
            int left = 0;
            while(left <= right){
                int mid = (left + right)/2;
                if(nums[mid] == target){
                    return mid;
                }else if(nums[mid] > target){
                    right = mid -1;
                }else{
                    left = mid+1;
                }
            }
    
            return -1;
        }
    };