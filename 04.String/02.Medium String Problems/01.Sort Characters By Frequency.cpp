
class Solution {
    public:
        string frequencySort(string s) {
           unordered_map<char, int> mp;
            // Count frequency of each character
            for (char c : s) {
                mp[c]++;
            }
    
            // Move map contents to a vector of pairs
            vector<pair<char, int>> vecmp(mp.begin(), mp.end());
    
            // Sort the vector by frequency (descending)
            sort(vecmp.begin(), vecmp.end(), [](pair<char, int> &a, pair<char, int> &b) {
                return a.second > b.second; 
            });
    
            string ans = "";
    
            // Build the result string based on frequency
            for (auto &[ch, freq] : vecmp) {
                ans += string(freq, ch); // Append 'ch' repeated 'freq' times
            }
    
            return ans;
        
        }
    };