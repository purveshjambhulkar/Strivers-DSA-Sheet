class Solution {
    public:
        bool isAnagram(string s, string t) {
    
            // Approach 3 - Sorting
            // initial check
            if (s.length() != t.length()) {
                return false;
            }
            sort(s.begin() , s.end());
            sort(t.begin() , t.end());
            return s==t;
    
    
    
    
            // Approach 2 - Brute force (this approach fails when there are repeated
            // elements)
    
            // initial check
            //  if(s.length() != t.length()){
            //      return false;
            //  }
    
            // for (int i = 0; i < s.length(); i++) {
            //     char ch = s[i];
            //     bool flag = false;
            //     for (int j = 0; j < t.length(); j++) {
            //         if (s[i] == t[j]) {
            //             flag = true;
            //         }
            //     }
            //     if (!flag) {
            //         return false;
            //     }
            // }
    
            // return true;
    
            // Approach 1 - Sum the char of string (but this approach may not work
            // in some cases)
    
            // initial check
            //  if(s.length() != t.length()){
            //      return false;
            //  }
            //  int x = 0  ;
            //  int y = 0;
    
            // for(int i = 0 ; i < s.length() ; i++){
            //     x+= (s[i] - '0');
            //     y+= (t[i] - '0');
            // }
    
            // return x== y;
        }
    };