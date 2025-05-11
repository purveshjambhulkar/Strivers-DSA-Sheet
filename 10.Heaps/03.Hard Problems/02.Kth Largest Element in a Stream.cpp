class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            if (minHeap.size() < k) {
                minHeap.push(num);
            } else if (num > minHeap.top()) {
                minHeap.push(num);
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to store the k largest elements
};

// Approach 1 - TLE

// class KthLargest {
// public:
//     int k ;

//     vector<int> num;

//     KthLargest(int k, vector<int>& nums) {
//         for(int i : nums){
//             num.push_back(i);
//         }

//         this->k = k;

//     }

//     int kthLargest(vector<int> num , int k){
//         priority_queue<int , vector<int> , greater<int>> minHeap;

//         for(int i : num){
//             minHeap.push(i);
//             if(minHeap.size() > k){
//                 minHeap.pop();
//             }
//         }
//         return minHeap.top();
//     }

//     int add(int val) {
//         num.push_back(val);
//         return kthLargest(num , k);
//     }
// };

// /**
//  * Your KthLargest object will be instantiated and called as such:
//  * KthLargest* obj = new KthLargest(k, nums);
//  * int param_1 = obj->add(val);
//  */