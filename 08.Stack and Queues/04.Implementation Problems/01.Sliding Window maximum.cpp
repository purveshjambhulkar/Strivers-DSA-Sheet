class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> dq; // stores *indices*
            vector<int> result;
    
            for (int i = 0; i < nums.size(); ++i) {
                // Remove out-of-bound indices from the front
                if (!dq.empty() && dq.front() == i - k)
                    dq.pop_front();
    
                // Remove smaller elements from the back
                while (!dq.empty() && nums[dq.back()] < nums[i])
                    dq.pop_back();
    
                dq.push_back(i);
    
                // Start adding max elements to result from i >= k - 1
                if (i >= k - 1)
                    result.push_back(nums[dq.front()]);
            }
    
            return result;
        }
    };
    