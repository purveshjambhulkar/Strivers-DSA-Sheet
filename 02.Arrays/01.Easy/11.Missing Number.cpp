class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Optimal Sol
        int n = nums.size();
        int sumN = n * (n+1) / 2;
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        return(sumN - sum);
    }

};