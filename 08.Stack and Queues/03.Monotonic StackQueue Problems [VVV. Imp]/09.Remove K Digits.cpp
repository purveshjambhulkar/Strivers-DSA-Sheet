class Solution {
    public:
        string removeKdigits(string num, int k) {
            stack<char> st;
    
            for (char ch : num) {
                while (!st.empty() && k > 0 && st.top() > ch) {
                    st.pop();
                    k--;
                }
                st.push(ch);
            }
    
            // If still have k digits to remove
            while (k > 0 && !st.empty()) {
                st.pop();
                k--;
            }
    
            // Build the resulting string
            string result;
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
            reverse(result.begin(), result.end());
    
            // Remove leading zeros
            int nonZeroIndex = 0;
            while (nonZeroIndex < result.size() && result[nonZeroIndex] == '0') {
                nonZeroIndex++;
            }
            result = result.substr(nonZeroIndex);
    
            return result.empty() ? "0" : result;
        }
    };
    