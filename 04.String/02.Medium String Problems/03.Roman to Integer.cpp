class Solution {
    public:
        int romanToInt(string s) {
            unordered_map<char, int> mp = {
                {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                {'C', 100}, {'D', 500}, {'M', 1000}};
    
            //Approach 1 
    
            int sum = 0;
            int size = s.length();
            for(int i =1; i < size ; i++){
                if(mp[s[i - 1]] < mp[s[i]]){
                    sum -= mp[s[i - 1]];
                }else if(mp[s[i - 1]] >= mp[s[i]]){
                    sum += mp[s[i - 1]];
                }
            }
            sum += mp[s[size - 1]];
    
            return sum;
        }
    };