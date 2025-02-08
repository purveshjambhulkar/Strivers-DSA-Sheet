class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
           
            // Approach 3.1 - Space optimized - w/o using extra space
            int p1 = m - 1; // Last valid element in nums1
            int p2 = 0;     // First element in nums2
    
            // Swap elements to move the larger ones to nums2 if needed
            while (p1 >= 0 && p2 < n) {
                if (nums1[p1] > nums2[p2]) {
                    swap(nums1[p1], nums2[p2]);
                    p1--;
                    p2++;
                } else {
                    break; // Already sorted, no need to swap further
                }
            }
    
            // Sort both arrays again to maintain order
            sort(nums1.begin(),
                 nums1.begin() + m); // Sort only valid elements in nums1
            sort(nums2.begin(), nums2.end());
    
            // Copy nums2 elements back into nums1
            for (int i = 0; i < n; i++) {
                nums1[m + i] = nums2[i];
            }
    
    
    
    
    
            // Approach 2 - using extra space and 2 pointer approach
    
            // vector<int> ans;
            // int p1 = 0 , p2 = 0 ;
            // while(p1 < m && p2 < n){
            //     if(nums1[p1] <= nums2[p2]){
            //         ans.push_back(nums1[p1++]);
            //     }else{
            //         ans.push_back(nums2[p2++]);
            //     }
            // }
            // while(p1 < m - n){
            //     ans.push_back(nums1[p1++]);
            // }
            // while(p2 < n){
            //     ans.push_back(nums2[p2++]);
            // }
    
            // nums1 = ans;
    
            // //Approach 1
            // for(int i : nums2){
            //     nums1[m] = i;
            //     m++;
            // }
            // sort(nums1.begin() , nums1.end());
        }
    };