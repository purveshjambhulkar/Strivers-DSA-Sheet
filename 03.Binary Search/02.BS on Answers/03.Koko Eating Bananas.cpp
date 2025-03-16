class Solution {
    public:
        // int findMax(vector<int>& piles) {
        //     int max = 0;
        //     for (int i : piles) {
        //         if (i > max) {
        //             max = i;
        //         }
        //     }
        //     return max;
        // }
    
        // Helper function to calculate total hours needed for a given eating speed
        int totalHR(vector<int>& piles, int perHR) {
            int total = 0;
            for (int i : piles) {
                // Integer math alternative to ceil((double)i / perHR)
                total += (i + perHR - 1) / perHR;
            }
            return total;
        }
    
        // Main function to find the minimum eating speed
        int minEatingSpeed(vector<int>& piles, int h) {
            int low = 1;
            int high = *max_element(piles.begin(), piles.end());
    
            // Binary search for the optimal speed
            while (low < high) { // Use < instead of <= for tighter bounds
                int mid = low + (high - low) / 2;
    
                int totalHr = totalHR(piles, mid);
                if (totalHr <= h) {
                    high = mid; // Move towards smaller speeds
                } else {
                    low = mid + 1; // Increase speed if total hours exceed h
                }
            }
    
            return low; // Low will hold the minimum feasible speed
        }
    };