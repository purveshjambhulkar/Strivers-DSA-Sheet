class Solution {
    public:
        int search(vector<int>& nums, int target) {
            
            //Approach2 - Bin Search
    
            int start = 0;
            int end = nums.size() -1;
            while(start<= end){
                int mid = start + (end - start)/2;
    
                if(nums[mid] == target){
                    return mid;
                }
                if(nums[start]<=nums[mid])
                {
                    if(nums[start] <= target && nums[mid] > target){
                        end = mid- 1;
                    }
                    else{
                        start = mid+1;
                    }
                }
                else{
                    if(nums[mid] < target && target <= nums[end]){
                        start = mid+1;
                    } else{
                        end =mid -1;
                    }
                }
    
                
            }
            return -1;
             
    
            //Approach 1 - Linear Search
            // for(int  i= 0; i <nums.size();i++){
            //     if(nums[i] == target){
            //         return i;
            //     }
            // }
            // return -1;
        }
    };