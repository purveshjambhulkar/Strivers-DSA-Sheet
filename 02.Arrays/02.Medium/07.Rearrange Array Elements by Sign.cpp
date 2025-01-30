class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // Approach 2 - Optimal in one o(n) iteration and sc- o(n)
        int n = nums.size();
        int pos_ind = 0;
        int neg_ind = 1;
        vector<int> ans(n, 2);
        for (int i : nums) {
            if (i > 0) {
                ans[pos_ind] = i;
                pos_ind += 2;
            }else{
                ans[neg_ind] = i;
                neg_ind+=2;
            }
        }
        return ans;

        // //Approach 1 - Brute Force- tc - o(n) and sc - o(n)
        // int n = nums.size();
        // vector<int> pos;
        // vector<int> neg;

        // for(int i : nums){
        //     if(i > 0 ){
        //         pos.push_back(i);
        //     }else{
        //         neg.push_back(i);
        //     }
        // }

        // for(int i = 0 ,  j = 0; i < n/2 ;i++ ){
        //     nums[j++] = pos[i];
        //     nums[j++] = neg[i];
        // }
        // return nums;
    }
};