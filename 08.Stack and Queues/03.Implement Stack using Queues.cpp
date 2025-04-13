class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    

    MyStack() {
        
    }
    
    void push(int x) {
        if(empty()){
            q1.push(x);
            return;
        }

        while(!q1.empty()){
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }

        q1.push(x);
        while(!q2.empty()){
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
    }
    
    int pop() {
        if(empty()){
            return -1;
        }

        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */