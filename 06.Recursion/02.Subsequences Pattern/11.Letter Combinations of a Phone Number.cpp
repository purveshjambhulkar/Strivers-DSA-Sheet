class Solution {
    private : 
        void solve(string digits ,string output,int index ,  vector<string> &ans  ,string mapping[]){
            //base case
            if(index >= digits.length()){
                ans.push_back(output);
                return ;
            }
    
            int number  = digits[index] - '0';
            string value = mapping[number]; /*If digits[index] is '3' (whose ASCII value is 51), subtracting '0' (ASCII value 48) from it gives 3, which is the desired numeric value.
    So, digits[index] - '0' performs this conversion from the ASCII value of the character representing a digit to the actual numeric value it represents*/
    
            for(int i = 0 ; i < value.length() ; i++){
                output.push_back(value[i]);
                solve(digits , output , index+1 , ans , mapping);
                output.pop_back();
            }
    
        }
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> ans ;
            string output ; 
            int index = 0 ;
            if(digits.length() == 0 ){
                return ans;
            }
            string mapping[10] = {"" , "" , "abc" ,"def" , "ghi" ,"jkl" ,"mno" , "pqrs" , "tuv" ,"wxyz"};
            solve(digits , output , index , ans , mapping);
            return ans ;
        }
    };