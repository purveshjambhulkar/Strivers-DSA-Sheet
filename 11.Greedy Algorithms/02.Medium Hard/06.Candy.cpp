    #include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        
        vector<int> candies(n, 1);
        
        // Left pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        
        // Right pass and final calculation
        int total = candies[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
            total += candies[i];
        }
        
        return total;
    }
};

// #include <vector>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         if (n == 0) return 0;
        
//         vector<int> left(n, 1);
//         vector<int> right(n, 1);
        
//         // Left pass
//         for (int i = 1; i < n; i++) {
//             if (ratings[i] > ratings[i-1]) {
//                 left[i] = left[i-1] + 1;
//             }
//         }
        
//         // Right pass
//         for (int i = n-2; i >= 0; i--) {
//             if (ratings[i] > ratings[i+1]) {
//                 right[i] = right[i+1] + 1;
//             }
//         }
        
//         int total = 0;
//         for (int i = 0; i < n; i++) {
//             total += max(left[i], right[i]);
//         }
        
//         return total;
//     }
// };