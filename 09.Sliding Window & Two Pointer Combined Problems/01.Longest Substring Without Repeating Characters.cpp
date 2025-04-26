class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.length();
            if(n == 0){
                return 0;
            }
            unordered_map<char , int> mpp;
            int left = 0;
            int right  = 0 ;
            int max_len = 0;
    
            while(right < n){
                if(mpp.find(s[right]) != mpp.end() && mpp[s[right]] >= left){
                    left = mpp[s[right]] + 1;
                }
    
    
                mpp[s[right]]  = right;
    
    
                max_len = max(max_len , right - left + 1);
    
                right++;
            }
    
            return max_len;
        }
    };