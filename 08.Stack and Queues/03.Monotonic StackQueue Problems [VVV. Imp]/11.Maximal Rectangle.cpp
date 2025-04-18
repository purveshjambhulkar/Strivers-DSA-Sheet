class Solution {
    public:
        int largestRectangleArea(vector<int>& arr) {
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
    
            int maxArea = 0;
            for (int i = 0; i < arr.size(); i++) {
                int area = arr[i] * (nse[i] - pse[i] - 1);
                maxArea = max(maxArea, area);
            }
            return maxArea;
        }
    
        int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.empty() || matrix[0].empty()) return 0;
    
            int rows = matrix.size(), cols = matrix[0].size();
            vector<vector<int>> presum(rows, vector<int>(cols, 0));
    
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (matrix[i][j] == '0') {
                        presum[i][j] = 0;
                    } else {
                        presum[i][j] = (i == 0 ? 1 : presum[i - 1][j] + 1);
                    }
                }
            }
    
            int maxArea = 0;
            for (int i = 0; i < rows; i++) {
                maxArea = max(maxArea, largestRectangleArea(presum[i]));
            }
    
            return maxArea;
        }
    };
    