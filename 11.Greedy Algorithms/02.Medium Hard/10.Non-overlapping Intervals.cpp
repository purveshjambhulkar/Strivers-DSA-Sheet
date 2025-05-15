class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int last = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last) {
                ans++; // overlap, remove current
            } else {
                last = intervals[i][1]; // no overlap, update last
            }
        }

        return ans;
    }
};