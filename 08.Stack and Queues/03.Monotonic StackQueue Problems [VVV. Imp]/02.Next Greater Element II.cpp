class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
    
            // Approach 2 using monotonic stacks
    
            stack<int> st;
            vector<int> ans(nums.size(), -1);
            int n = nums.size();
    
            for (int i = 2 * n - 1; i >= 0; i--) {
                while (!st.empty() && st.top() <= nums[i % n]) {
                    st.pop();
                }
    
                if (i < n) {
                    ans[i] = st.empty() ? -1 : st.top();
                }
    
                st.push(nums[i % n]);
            }
    
            return ans;
    
            // Approach 1
    
            // vector<int> result(nums.size() , -1);
            // int n = nums.size();
            // for(int i = 0 ; i < n ; i++){
    
            //     int num = nums[i];
    
            //     for(int j = i ; j <= i + n -1 ;j++){
            //         int index = j % n;
    
            //         if(nums[index] > num){
            //             result[i] = nums[index];
            //             break;
            //         }
            //     }
    
            // }
            // return result;
        }
    };