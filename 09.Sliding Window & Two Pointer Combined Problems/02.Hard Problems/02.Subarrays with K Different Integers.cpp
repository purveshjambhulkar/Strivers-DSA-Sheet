class Solution {
    public:
    
        int Util(vector<int>& nums, int k){
    
            //initialization
            int left = 0;
            int right = 0;
            unordered_map<int , int> mpp;
            int count = 0;
            int n = nums.size();
    
            while(right < n){
                mpp[nums[right]]++;
    
                //check if it is valid
                while(mpp.size() > k){
                    mpp[nums[left]]--;
                    if(mpp[nums[left]] == 0){
                        mpp.erase(nums[left]);
                    }
                    left++;
                }
    
                count += right - left +1;
                right++;
    
            }
    
            return count;
    
    
    
    
        }
    
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            // Exactly k distinct = At most k distinct - At most k - 1 distinct
    
            return (Util(nums, k) - Util(nums, k - 1));
        }
    };