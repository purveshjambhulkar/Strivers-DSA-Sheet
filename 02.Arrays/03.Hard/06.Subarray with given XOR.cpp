int Solution::solve(vector<int> &A, int B) {
    
    //Approach 2- Optimization
    
    int n = A.size();
    int maxSub = 0;
    int preXOR = 0;
    unordered_map<int, int> mpp; // Stores prefix XOR frequencies

    for (int i = 0; i < n; i++) {
        preXOR ^= A[i];

        // If the XOR of the entire subarray [0...i] is B
        if (preXOR == B) {
            maxSub++;
        }

        // Find occurrences of (preXOR ^ B) in the map
        int X = preXOR ^ B;
        if (mpp.find(X) != mpp.end()) {
            maxSub += mpp[X]; // Add the number of times (preXOR ^ B) has occurred
        }

        // Store the prefix XOR frequency in the map
        mpp[preXOR]++;
    }

    return maxSub;
    
    //Appraoch 1 - Brute Force
    // int n = A.size();
    // int maxSub = 0;
    
    // for(int i = 0 ; i < n ; i++){
    //     int sum = A[i];
    //     if(sum == B){
    //         maxSub++;
    //     }
    //     for(int j = i+1 ; j < n ;j++){
    //         sum ^= A[j];
    //         if(sum == B){
    //             maxSub++;
    //                         }
    //     }
    // }
    
    // return maxSub;
}
