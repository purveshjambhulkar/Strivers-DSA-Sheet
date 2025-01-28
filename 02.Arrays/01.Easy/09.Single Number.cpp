class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //approach 3 - optimal solution - using XOR - o(n) tc and o(1) sc

        int Xor = 0;
        for(int i : nums){
            Xor = Xor^ i;
        }
        return Xor;



        //approach 2 - hashing - O(n) tc and o(n) sc
        // unordered_map<int, int> map;
        // for(int i : nums){
        //     map[i]++;
        // }
        // for(int i : nums){
        //     if(map[i] == 1){
        //         return i;
        //     }
        // }


        //approach 1 - sort and travserse
        // sort(nums.begin() , nums.end());
        // for(int i = 0; i < nums.size() - 1; i++){
        //     if(nums[i] != nums[i+1]){
        //         return nums[i];
        //     }
        //     i++;
        // }
        // return nums.back();
    }
};