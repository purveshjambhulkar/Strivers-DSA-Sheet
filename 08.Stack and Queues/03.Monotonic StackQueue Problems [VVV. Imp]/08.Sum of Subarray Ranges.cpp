class Solution {
    public:
        long long sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
    
            stack<int> st;
            vector<int> nse(n, n);
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    nse[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
    
            while (!st.empty()) st.pop();
    
            vector<int> pse(n, -1);
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    pse[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
    
            long long total = 0;
            for (int i = 0; i < n; i++) {
                long long left = i - pse[i];
                long long right = nse[i] - i;
                total += (long long)arr[i] * left * right;
            }
    
            return total;
        }
    
        long long sumSubarrayMaxs(vector<int>& arr) {
            int n = arr.size();
            stack<int> st;
    
            vector<int> nge(n, n);
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] < arr[i]) {
                    nge[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
    
            while (!st.empty()) st.pop();
    
            vector<int> pge(n, -1);
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] <= arr[i]) {
                    pge[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
    
            long long total = 0;
            for (int i = 0; i < n; i++) {
                long long left = i - pge[i];
                long long right = nge[i] - i;
                total += (long long)arr[i] * left * right;
            }
    
            return total;
        }
    
        long long subArrayRanges(vector<int>& nums) {
            return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    
             // //Approach 1 - Brute Force
    
            // long long ans = 0;
    
            // for(int i = 0 ; i < nums.size() ;i++){
    
            //     int min = nums[i];
            //     int max = nums[i];
    
            //     for(int j = i +1; j < nums.size() ; j++){
    
            //         if(nums[j] < min){
            //             min = nums[j];
            //         }
    
            //         if(nums[j] > max){
            //             max = nums[j];
            //         }
    
            //         ans += (max - min);
    
            //     }
    
            // }
    
            // return ans;
        }
    };
    