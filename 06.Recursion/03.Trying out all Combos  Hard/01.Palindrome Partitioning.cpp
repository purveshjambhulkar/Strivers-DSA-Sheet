class Solution {
    public:
        bool isPalindrome(string s, int start, int end) {
            while (start <= end) {
                if (s[start] != s[end]) {
                    return false;
                }
                start++;
                end--;
            }
            return true;
        }
    
        void partitionUtil(string s, vector<vector<string>>& ans,
                           vector<string> temp, int index) {
    
            // base case
            if (index == s.length() ) {
                ans.push_back(temp);
                return;
            }
    
            for (int i = index; i < s.length(); i++) {
                if (isPalindrome(s, index, i)) {
                    temp.push_back(s.substr(index,  i - index + 1));
                    partitionUtil(s, ans, temp, i + 1);
                    temp.pop_back();
                }
            }
        }
    
        vector<vector<string>> partition(string s) {
            vector<vector<string>> ans;
            vector<string> temp;
            partitionUtil(s, ans, temp, 0);
            return ans;
        }
    };