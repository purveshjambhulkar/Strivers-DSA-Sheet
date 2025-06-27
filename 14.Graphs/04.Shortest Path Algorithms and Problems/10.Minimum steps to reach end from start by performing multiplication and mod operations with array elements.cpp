// problem link - https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1


class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 100000; 

        if (start == end) {
            return 0;
        }

        vector<int> dist(mod, -1); 

        queue<pair<int, int>> q;

        q.push({0, start});
        dist[start] = 0; 

        while (!q.empty()) {
            int steps = q.front().first;  
            int current_num = q.front().second; 
            q.pop();

            for (int factor : arr) {
                long long next_num_ll = (long long)current_num * factor; 
                int next_num = next_num_ll % mod; 

                if (dist[next_num] == -1) {
                    dist[next_num] = steps + 1; 

                    if (next_num == end) {
                        return steps + 1;
                    }
                    
                    q.push({steps + 1, next_num});
                }
            }
        }

        return -1;
    }
};
