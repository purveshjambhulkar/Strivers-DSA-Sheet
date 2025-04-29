// problem link - https://leetcode.com/problems/fruit-into-baskets/


class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
    
            //Approach 2 - 2 ptr + sliding window
    
           int n = fruits.size();
            int left = 0;
            int right = 0;
            unordered_map<int , int > mpp;
    
            int max_fruits = 0;
    
            while(right < n){
                mpp[fruits[right]]++; 
    
                // Shrink window if more than 2 types
                while(mpp.size() > 2){
                    mpp[fruits[left]]--;
                    if(mpp[fruits[left]] == 0){
                        mpp.erase(fruits[left]);
                    }
                    left++;
                }
    
                max_fruits = max(max_fruits , right - left + 1);
                right++;
            }
    
            return max_fruits;
    
    
    
            //Approach 1 - Time Limited Exceeded
            
            // int n = fruits.size();
            // int max_fruits = 0;
    
            // for (int i = 0; i < n; i++) {
            //     int f1 = fruits[i];
            //     int f2 = -1;
            //     int count = 0;
            //     for (int j = i; j < n; j++) {
            //         if (fruits[j] == f1 || (f2 != -1 && fruits[j] == f2)) {
            //             count++;
            //         } else if (f2 == -1) {
            //             f2 = fruits[j];
            //             count++;
            //         } else {
            //             break;
            //         }
            //     }
            //     max_fruits = max(max_fruits, count);
            // }
    
            // return max_fruits;
        }
    };
    