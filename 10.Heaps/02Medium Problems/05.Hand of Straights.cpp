#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& pair : count) {
            minHeap.push(pair.first);
        }

        while (!minHeap.empty()) {
            int first = minHeap.top();
            for (int i = 0; i < groupSize; ++i) {
                int current = first + i;
                if (count[current] == 0) {
                    return false;
                }
                count[current]--;
                if (count[current] == 0) {
                    if (current != minHeap.top()) {
                        return false;
                    }
                    minHeap.pop();
                }
            }
        }

        return true;
    }
};