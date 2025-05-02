class Solution {
    public:
        int characterReplacement(string s, int k) {
            // 2 pointer + Sliding Window
    
            int left = 0;
            int right = 0;
            int maxLen = 0;
    
            int n = s.length();
            int maxFreq = 0;
            unordered_map<char, int> mpp;
        
            while (right < n) {
                mpp[s[right]]++;
                maxFreq = max(maxFreq, mpp[s[right]]);
    
                while (((right - left + 1) - maxFreq) > k) {
                    mpp[s[left]]--;
                    left++;
                    maxFreq = 0;
                    for (auto& [key, val] : mpp) {
                        if (val > maxFreq) {
                            maxFreq = val;
                        }
                    }
                }
    
                maxLen = max(maxLen , right - left + 1);
    
                right++;
            }
    
            return maxLen;
        }
    };