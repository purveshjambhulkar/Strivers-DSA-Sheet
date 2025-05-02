#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    // Helper function to count subarrays with at most k odd numbers
    int atMostK(vector<int>& nums, int k) {
        int left = 0;
        int oddCount = 0;
        int result = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 != 0) {
                oddCount++;
            }

            // Shrink the window until the number of odd numbers is <= k
            while (oddCount > k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }

            // Count the number of subarrays ending at 'right' with at most k odds
            result += right - left + 1;
        }

        return result;
    }
};





// #include <unordered_map>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         unordered_map<int, int> prefixCount;
//         prefixCount[0] = 1; // Base case: 0 odds before any element

//         int oddCount = 0; // Track number of odd elements encountered
//         int result = 0;   // Result to store the number of nice subarrays

//         for (int num : nums) {
//             // Increment odd count if current number is odd
//             if (num % 2 != 0) {
//                 oddCount++;
//             }

//             // Check how many times oddCount - k has appeared in prefixCount
//             if (prefixCount.count(oddCount - k)) {
//                 result += prefixCount[oddCount - k];
//             }

//             // Update prefixCount with the current oddCount
//             prefixCount[oddCount]++;
//         }

//         return result;
//     }
// };
