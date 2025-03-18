//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        // code here
        //Approach 2
        int size = nums1.size() + nums2.size();
        int count = 0;
        int countx = 0;
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            
            if(nums1[i] < nums2[j]){
                countx = nums1[i++];
            }else{
                countx = nums2[j++];
            }
            if(count == k-1){
                return countx;
            }
            count++;
            
        }
        
        while(i < nums1.size()){
            countx= nums1[i++];
             if(count == k-1){
                return countx;
            }
            count++;
        }
        while(j < nums2.size()){
            countx= nums2[j++];
             if(count == k-1){
                return countx;
            }
            count++;
        }
        
        
        return countx;
        
        
        
        
        // //Approach 1 
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
        
        // return temp[k-1];
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends