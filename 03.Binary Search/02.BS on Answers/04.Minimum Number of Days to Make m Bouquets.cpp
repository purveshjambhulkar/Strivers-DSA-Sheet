class Solution {
    public:
        // Helper function to count how many bouquets can be made with a given "day"
        int solve(vector<int>& bloomDay, int k, int day) {
            int bouquets = 0;
            int flowers = 0;
    
            for (int bloom : bloomDay) {
                if (bloom <= day) {
                    flowers++; // This flower is bloomed and usable
                } else {
                    flowers = 0; // Reset if we hit an unbloomed flower
                }
    
                if (flowers == k) {
                    bouquets++;
                    flowers = 0; // Reset after making a bouquet
                }
            }
    
            return bouquets;
        }
    
        int minDays(vector<int>& bloomDay, int m, int k) {
            // Edge case: if total flowers are less than needed for m bouquets
            if ((long long)m * k > bloomDay.size())
                return -1;
    
            // Define the range of days
            int left = *min_element(bloomDay.begin(), bloomDay.end());
            int right = *max_element(bloomDay.begin(), bloomDay.end());
            int ans = -1;
    
            // Perform binary search on days
            while (left <= right) {
                int mid = left + (right - left) / 2;
    
                // Check how many bouquets we can make with this day
                int bouquets = solve(bloomDay, k, mid);
    
                if (bouquets >= m) {
                    // If we can make at least m bouquets, try for fewer days
                    ans = mid;
                    right = mid - 1;
                } else {
                    // Not enough bouquets, we need more days
                    left = mid + 1;
                }
            }
    
            return ans;
        }
    };