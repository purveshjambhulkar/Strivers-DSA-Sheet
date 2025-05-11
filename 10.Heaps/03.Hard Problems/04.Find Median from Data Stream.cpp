class MedianFinder {
private:
    priority_queue<int> maxHeap; // stores smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // stores larger half

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }


    //Approach 1  - TLE

    // vector<int> med;

    // MedianFinder() {
        
    // }
    
    // void addNum(int num) {
    //     med.push_back(num);
    //     sort(med.begin() , med.end());
    // }
    
    // double findMedian() {
    //     int n = med.size();
    //     if(n % 2 == 0){
    //         int ind1 = n / 2;
    //         int ind2 = ind1+1;
    //         double ans = (double)(med[ind1-1] + med[ind2-1]) /2.0;
    //         return ans;
    //     }else {
    //         int ind = (n / 2) + 1;
    //         double ans =med[ind -1];
    //         return ans;
    //     }
    // }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */