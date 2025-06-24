// problem link - https://www.geeksforgeeks.org/problems/alien-dictionary/1


class Solution {
public:
    string findOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        unordered_set<char> all_chars;

        for (const string& word : words) {
            for (char c : word) {
                all_chars.insert(c);
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];

            if (s1.length() > s2.length() && s1.substr(0, s2.length()) == s2) {
                return "";
            }

            int len = min(s1.length(), s2.length());
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    if (adj[s1[j]].find(s2[j]) == adj[s1[j]].end()) {
                        adj[s1[j]].insert(s2[j]);
                        indegree[s2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for (char c : all_chars) {
            if (indegree[c] == 0) {
                q.push(c);
            }
        }

        string result = "";
        int count = 0;

        while (!q.empty()) {
            char u = q.front();
            q.pop();
            result += u;
            count++;

            if (adj.count(u)) { 
                for (char v : adj[u]) {
                    indegree[v]--;
                    if (indegree[v] == 0) {
                        q.push(v);
                    }
                }
            }
        }

        if (count != all_chars.size()) {
            return "";
        }

        return result;
    }
};