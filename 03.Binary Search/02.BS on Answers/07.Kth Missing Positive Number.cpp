class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
    
            //Approach 1 - Brute Force
            for(int i : arr){
                if(i <= k){
                    k++;
                }
                else{
                    break;
                }
            }
            return k;
        }
    };