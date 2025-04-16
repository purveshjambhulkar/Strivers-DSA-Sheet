class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    
            //approach 2 - using stacks
    
            unordered_map<int , int> mpp;
            stack<int> st;
    
            for(int i = nums2.size() - 1 ;i>=0; i--){
                 
                while(!st.empty() && st.top() <= nums2[i]){
                    st.pop();
                }
    
                            if (st.empty()) {
                    mpp[nums2[i]] = -1;
                } else {
                    mpp[nums2[i]] = st.top();
                }
    
                st.push(nums2[i]);
    
    
    
            }
    
             // Step 2: Build the result for nums1 based on the map
            vector<int> result;
            for (int num : nums1) {
                result.push_back(mpp[num]);
            }
    
            return result;
            
            
            // //approach 1 using loops 
    
            // unordered_map<int , int> mpp;
    
            // for(int i = 0 ; i < nums1.size() ; i++){
    
            //     int num = nums1[i];
            //     mpp[num] = -1;
            //     bool found = false;
    
            //     for(int j = 0 ; j < nums2.size() ; j++){
            //         if(nums2[j] == num){
            //             found = true;
            //         }
    
            //         if(found && nums2[j] > num){
            //             mpp[num] = nums2[j];
            //             break;
            //         }
            //     }
    
            // }
    
            // vector<int> result;
            // for(int i : nums1){
            //     result.push_back(mpp[i]);
            // }
    
            // return result;
    
    
        }
    };