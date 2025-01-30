class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //Approach 3 - Using Hashmap- tc o(n*log n)
        unordered_map<int , int> map;
        for(int i = 0;i< nums.size();i++){
            int k = target - nums[i];
            if(map.find(k) != map.end()){
                return{map[k] , i};
            }else{
                map[nums[i]] = i;
            }

        }
        return {-1,-1};

        // Approach 2 - 2 Pointers - Even if the code is right its now executing properly
        //sort(nums.begin() , nums.end());
        // int left = 0 ;
        // int right = nums.size() - 1;
        // while (left < right) 
        // {
        //     int sum = nums[left] + nums[right] ;
        //     if(sum == target){
        //         return {left, right};
        //     }
        //     if(sum < target){
        //         left++ ;
        //     }
        //     else{
        //         right-- ;
        //     }

        // }
        // return {-1, -1};// Return an empty vector if no pair is found

        // approach 1 - brute force
        //     for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[i] + nums[j] == target) { // Check if the sum equals
        //         the target
        //             return {i, j}; // Return the indices if the condition is
        //             met
        //         }
        //     }
        // }
        // return {}; // Return an empty vector if no pair is found
    }
};