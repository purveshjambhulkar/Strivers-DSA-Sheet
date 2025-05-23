class MyQueue {
    public:
        stack<int> s1;
        stack<int> s2;
    
        MyQueue() {
            
        }
        
        void push(int x) {
            if(empty()){
                s1.push(x);
                return;
            }
    
            while(!s1.empty()){
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
    
            s1.push(x);
    
            while(!s2.empty()){
                int temp = s2.top();
                s2.pop();
                s1.push(temp);
            }
        }
        
        int pop() {
            if(empty()){
                return -1;
            }
            int temp = s1.top();
            s1.pop();
            return temp;
        }
        
        int peek() {
            return s1.top();
        }
        
        bool empty() {
            if(s1.empty()){
                return true;
            }else{
                return false;
            }
        }
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */