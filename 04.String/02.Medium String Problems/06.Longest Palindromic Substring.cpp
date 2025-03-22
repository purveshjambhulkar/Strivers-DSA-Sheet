class Solution {
    public:
    
        int longestPalindromeUtil(string s , int left , int right){
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            return right - left - 1;
        }
    
        string longestPalindrome(string s) {
            int n = s.length();
            int start = 0;
            int end = 0;
            int max_len = 0;
    
            for (int i = 0; i < n; i++) {
                int odd = longestPalindromeUtil(s, i, i);
                int even = longestPalindromeUtil(s, i, i + 1);
                max_len = max(odd, even);
    
                if (max_len > end - start) {
                    start = i - (max_len - 1) / 2;
                    end = i + max_len / 2;
                }
            }
            return s.substr(start, end - start + 1);
        }
    };