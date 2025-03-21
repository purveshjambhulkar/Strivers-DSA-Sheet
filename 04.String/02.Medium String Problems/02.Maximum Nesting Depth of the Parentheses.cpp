class Solution {
    public:
        int maxDepth(string s) {
    
            //Approach 2 - W/o stack
    
            int tempCount = 0;
            int maxD = 0;
            for(char ch : s){
                if(ch == '('){
                    tempCount++;
                    maxD = max(tempCount , maxD);
                }else if(ch == ')'){
                    tempCount--;
                }
            }
            return maxD;
    
    
    
            // Approach 1 - using stack
            // traverse the string
            // if curr char is ( then add in stack and increase the count of max
            // nested if curr char is )  then pop from stack and decrease the count
            // of maxnested
    
            // stack<int> st;
            // int tempCount = 0;
            // int maxD = 0;
            // for(char ch : s){
            //     if(ch == '('){
            //         st.push(ch);
            //         tempCount++;
            //         maxD = max(maxD , tempCount);
            //     }else if(ch == ')'){
            //         st.pop();
            //         tempCount--;
            //     }
            // }
            // return maxD;
    
        }
    };