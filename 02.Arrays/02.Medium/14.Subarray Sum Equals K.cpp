class Solution {
    public:
        int subarraySum(vector<int>& arr, int k) {
            // Appoach 2 
            int n = arr.size(); // size of the given array.
            unordered_map<int , int> mpp;
            int preSum = 0, cnt = 0;
    
            mpp[0] = 1; // Setting 0 in the map.
            for (int i = 0; i < n; i++) {
                // add current element to prefix Sum:
                preSum += arr[i];
    
                // Calculate x-k:
                int remove = preSum - k;
    
                // Add the number of subarrays to be removed:
                cnt += mpp[remove];
    
                // Update the count of prefix sum
                // in the map.
                mpp[preSum] += 1;
            }
            return cnt;
    
            // // Approch 1 - Brute Force | tc = o(n^2)
    
            // int count = 0;
            // for (int i = 0; i < nums.size(); i++) {
            //     int curr_sum = nums[i];
            //     if (curr_sum == k) {
            //         count++;
            //     }
            //     for (int j = i + 1; j < nums.size(); j++) {
    
            //         curr_sum += nums[j];
            //         if (curr_sum == k) {
            //             count++;
            //         }
            //     }
            // }
    
            // return count;
        }
    };