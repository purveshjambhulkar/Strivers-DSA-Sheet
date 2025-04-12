class Solution {
    public:
        vector<int> getPrimeFactors(int n) {
            vector<int> temp;
            for (int x = 2; x * x <= n; x++) {
                while (n % x == 0) {
                    temp.push_back(x);
                    n /= x;
                }
            }
            if (n > 1) {
                temp.push_back(n);
            }
            return temp;
        }
    
        vector<vector<int>> primeFactors(vector<int>& queries) {
            vector<vector<int>> ans;
            for (int i : queries) {
                ans.push_back(getPrimeFactors(i));
            }
            return ans;
        }
    };
    