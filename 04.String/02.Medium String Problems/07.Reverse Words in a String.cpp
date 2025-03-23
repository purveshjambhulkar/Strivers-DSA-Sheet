class Solution {
    public:
        string reverseWords(string s) {
            string ans = "";
            int i = 0;
            int j;
            while (i < s.length()) {
                // Skip leading spaces
                while (i < s.length() && s[i] == ' ') {
                    i++;
                }
                // Find the end of the word
                j = i + 1;
                while (j < s.length() && s[j] != ' ') {
                    j++;
                }
    
                // Extract the word correctly
                string word = s.substr(i, j - i);
                if (!word.empty()) {
                    ans = word + (ans.empty() ? "" : " ") + ans;
                }
                i = j + 1;
            }
    
            return ans;
        }
    };
    