class StockSpanner {
    public:
        stack<pair<int , int>> st;
        
        StockSpanner() {
            
        }
        
        int next(int price) {
            //Approach 2 - using stack
    
            int span = 1;
            while(!st.empty() && st.top().first <= price){
                span += st.top().second;
                st.pop();
            }
    
            st.push({price,span});
    
            return span;
    
        }
    };
    // class StockSpanner {
    // public:
    //     vector<int> stock;
     
    //     StockSpanner() {
            
    //     }
        
    //     int next(int price) {
    //         //Approach 1 - brute force
    
    //         stock.push_back(price);
    
    //         int count = 1;
    //         for(int i = stock.size() - 2; i >=0;i--){
    //             if(price >= stock[i]){
    //                 count++;
    //             }else{
    //                 break;
    //             }
    //         }
    
    //         return count;
    //     }
    // };
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */