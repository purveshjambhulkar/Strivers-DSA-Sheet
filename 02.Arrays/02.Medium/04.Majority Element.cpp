class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Approach 3 - Moose Voting Algorithm
        int ele ;
        int count = 0 ;
        for(int i : nums){
            if(count == 0){
                count++;
                ele = i;
            }else if(i == ele){
                count++;
            }else{
                count--;
            }
        }
        count=0;
        for(int i : nums){
            if(i == ele){
                count++;
            }
            if(count > nums.size()/2){
                return ele;
            }
        }
        return ele;

        //Approach 2 - Mapping - tc - o(n * log n)
        // unordered_map<int , int> map;
        // for(int i :nums){
        //     map[i]++;
        // }
        // int max = 0;
        // int maxEle = nums[0];
        // for(int i : nums){
        //     if(map[i] > max){
        //         max = map[i];
        //         maxEle = i;
        //     }
        // }
        // return maxEle;


        //Appraoch 1 - Brute Force
        // int maj = 0 ;
        // int ans = nums[0];
        // int n = nums.size();
        // for(int i =0; i < n ;i++){
        //     int currEle = nums[i];
        //     int currmaj = 0;
        //     for(int j = 0 ; j < n ;j++){
        //         if(nums[j] == currEle){
        //             currmaj++;
        //         }
        //     }
        //     if(currmaj > maj){
        //         ans = currEle;
        //     }
        // }

        // return ans;
    }
};