// link - https://takeuforward.org/plus/dsa/problems/shortest-job-first

class Solution {
   public:
    long long solve(vector<int>& bt) {
        // your code goes here
        sort(bt.begin() , bt.end());
        long long ans = 0;
        long long curr = 0;

        for(int i : bt){
          ans += curr;
          curr += i;
        }

        return ans / bt.size();
    }
};