class Solution {
    public:
        void generateUtil(int openP , int closeP , string s , int n , vector<string> &res){
            if(openP == closeP && openP + closeP == 2 * n){
                res.push_back(s);
                return;
            }
    
            if(openP < n){
                generateUtil(openP+1 , closeP , s + "(" , n ,res );
            }
            if(closeP < openP){
                generateUtil(openP , closeP + 1 , s+")" , n , res);
            }
        }
    
        vector<string> generateParenthesis(int n) {
            vector<string> res;
            generateUtil(0 ,0, "", n , res);
            return res;
        }
    };