class Solution {
    public:
        int reversePairs(vector<int>& nums) {
            //Approach 1 - Brute Force
    
            int n = nums.size();
            int count = 0;
            for(int i = 0 ; i < n ; i++){
                for(int j = i+1 ; j < n ; j++){
                    if(nums[i] > 2 * nums[j]){
                        count++;
                    }
                }       
            }
            return count;
        }
    };