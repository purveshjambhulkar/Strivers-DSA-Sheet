class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            // Approach 2 - Eliminating extra space
    
            int size = nums1.size() + nums2.size();
            int ind1 = (size / 2 - 1);
            int ind2 = (size / 2);
            int count = 0;
            int val1 = 0, val2 = 0;
            int i = 0, j = 0;
    
            // Merge both arrays without extra space
            while (i < nums1.size() && j < nums2.size()) {
                int current = (nums1[i] <= nums2[j]) ? nums1[i++] : nums2[j++];
    
                if (count == ind1)
                    val1 = current;
                if (count == ind2)
                    val2 = current;
                count++;
            }
    
            // Handle remaining elements in nums1
            while (i < nums1.size()) {
                int current = nums1[i++];
                if (count == ind1)
                    val1 = current;
                if (count == ind2)
                    val2 = current;
                count++;
            }
    
            // Handle remaining elements in nums2
            while (j < nums2.size()) {
                int current = nums2[j++];
                if (count == ind1)
                    val1 = current;
                if (count == ind2)
                    val2 = current;
                count++;
            }
    
            // Return the median
            return (size % 2 == 0) ? (val1 + val2) / 2.0 : val2;
        
    
        // // Approach 1 - join the both arrays and find median
    
        // vector<int> temp;
        // int i = 0;
        // int j = 0;
        // while (i < nums1.size() && j < nums2.size()) {
        //     if (nums1[i] > nums2[j]) {
        //         temp.push_back(nums2[j++]);
        //     } else {
        //         temp.push_back(nums1[i++]);
        //     }
        // }
    
        // if (i != nums1.size()) {
        //     for (int m = i; m < nums1.size(); m++) {
        //         temp.push_back(nums1[m]);
        //     }
        // }
        // if (j != nums2.size()) {
        //     for (int m = j; m < nums2.size(); m++) {
        //         temp.push_back(nums2[m]);
        //     }
        // }
    
        // if (temp.size() % 2 == 0) {
        //     double x = temp[temp.size()/2 - 1] ;
        //     double y = temp[(temp.size()/2)];
        //     return (x+y)/2;
    
        // } else {
        //     double x = temp[temp.size()/2];
        //     return x;
        // }
    }
    }
    ;