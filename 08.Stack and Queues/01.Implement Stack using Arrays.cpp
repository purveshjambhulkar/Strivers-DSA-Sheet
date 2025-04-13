// Stack class.
// problem link - https://www.naukri.com/code360/problems/stack-implementation-using-array_3210209?leftPanelTabValue=PROBLEM
//Using Arrays

class Stack {
    
    public:
        int *arr ;
        int capacity;
        int t;
        Stack(int capacity) {
            // Write your code here.
            arr = new int [capacity];
            this->capacity = capacity;
            this->t = -1;
        }
    
        void push(int num) {
            // Write your code here.
            if(isFull()){
                return ;
            }
            t++;
            arr[t] = num;
        }
    
        int pop() {
            // Write your code here.
            if(isEmpty()){
                return -1;
            }
            int topEle = arr[t];
            t--;
            return topEle;
    
        }
        
        int top() {
            // Write your code here.
            if(isEmpty()){
                return -1;
            }
            return arr[t];
        }
        
        int isEmpty() {
            // Write your code here.
            if(t == -1){
                return 1;
            }else{
                return 0;
            }
    
        }
        
        int isFull() {
            // Write your code here.
            if(t == capacity - 1){
                return 1;
            }
            else{
                return 0;
            }
        }
        
    };
    //Using Vectors
    
    // class Stack {
        
    // public:
    //     vector<int> st;
    //     int capacity;
    //     Stack(int capacity) {
    //         // Write your code here.
    //         vector<int> st(capacity);
    //         this->capacity = capacity;
    //     }
    
    //     void push(int num) {
    //         // Write your code here.
    //         if(isFull()){
    //             return ;
    //         }
    //         st.push_back(num);
    //     }
    
    //     int pop() {
    //         // Write your code here.
    //         if(isEmpty()){
    //             return -1;
    //         }
    //         int top = st.back();
    //         st.pop_back();
    //         return top;
    
    //     }
        
    //     int top() {
    //         // Write your code here.
    //         if(isEmpty()){
    //             return -1;
    //         }
    //         return st.back();
    //     }
        
    //     int isEmpty() {
    //         // Write your code here.
    //         if(st.size() == 0){
    //             return 1;
    //         }else{
    //             return 0;
    //         }
    
    //     }
        
    //     int isFull() {
    //         // Write your code here.
    //         if(st.size() == capacity){
    //             return 1;
    //         }
    //         else{
    //             return 0;
    //         }
    //     }
        
    // };
    