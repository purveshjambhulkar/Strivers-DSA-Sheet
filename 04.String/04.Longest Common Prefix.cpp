class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string ans = "";
            sort(strs.begin() , strs.end());
            int i = 0;
    
            while(true){
                if(i >= strs[0].length()){
                    return ans;
                }
                char c = strs[0][i];
                for(string str : strs){
                    if(str[i] != c){
                        return ans;
                    }
                }
                i++;
                ans+= c;
    
            }
        }
    };