class Solution {
    public:
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            const int MOD = 1e9 + 7;
    
            // Next Smaller Element (NSE)
            stack<int> st;
            vector<int> nse(n,
                            n); // default to n if no smaller element to the right
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    nse[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
    
            // Clear the stack
            while (!st.empty())
                st.pop();
    
            // Previous Smaller Element (PSE)
            vector<int> pse(n,
                            -1); // default to -1 if no smaller element to the left
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    pse[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
    
            // Calculate result
            long long total = 0;
            for (int i = 0; i < n; i++) {
                long long left = i - pse[i];
                long long right = nse[i] - i;
                // total += arr[i] * count_of_subarrays_where_arr[i]_is_min
    
                total = (total + (arr[i] * left % MOD) * right % MOD) % MOD;
            }
    
            return static_cast<int>(total);
        }
    };