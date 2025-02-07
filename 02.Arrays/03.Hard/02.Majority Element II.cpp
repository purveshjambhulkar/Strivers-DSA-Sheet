class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Appraoch 2 - hashing
        unordered_map<int, int> map;
        vector<int> ans;
        int min = nums.size()/3;
        for(int i : nums){
            map[i]++;
            if(map[i] == min){
                ans.push_back(i);
            }
        }
        return ans;
    }
};