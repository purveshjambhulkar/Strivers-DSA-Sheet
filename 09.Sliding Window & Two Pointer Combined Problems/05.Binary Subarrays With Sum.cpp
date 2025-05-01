class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            unordered_map<int, int> prefixCount;
            prefixCount[0] = 1;  // base case for exact sum
    
            int sum = 0;
            int result = 0;
    
            for (int num : nums) {
                sum += num;
    
                if (prefixCount.count(sum - goal)) {
                    result += prefixCount[sum - goal];
                }
    
                prefixCount[sum]++;
            }
    
            return result;
        }
    };