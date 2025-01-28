class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCons = 0;
        int tempMax = 0;
        for(int i : nums){
            if(i == 1){
                tempMax++;
                maxCons = max(maxCons , tempMax);
            }else{
                tempMax = 0;
            }
        }
        return maxCons;
    }
};