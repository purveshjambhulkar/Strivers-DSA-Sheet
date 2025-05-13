// link - https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        
        //Approach 2 - Using vector
        
         vector<pair<int, int>> meetings;
        for (int i = 0; i < start.size(); ++i) {
            meetings.push_back({end[i], start[i]});
        }
        
        // Sort meetings by end time
        sort(meetings.begin(), meetings.end());
        
        int count = 0;
        int lastEnd = -1;
        
        for (const auto& meeting : meetings) {
            if (meeting.second > lastEnd) {
                count++;
                lastEnd = meeting.first;
            }
        }
        
        return count;
        
        
        
        //Approach 1 - Using MinHeap
        
        // priority_queue<pair<int , int>, vector<pair<int , int>> , greater<pair<int , int>>> minHeap;
    
        // for(int i = 0 ; i < end.size() ;i++){
        //     minHeap.push({end[i] , start[i]});
        // }
        
        // int meetingPerformed = 0;
        // int endTime = -1;
        
        // while(!minHeap.empty()){
        //     int startT = minHeap.top().second;
            
            
        //     if(startT > endTime){
        //         meetingPerformed++;
        //         endTime = minHeap.top().first;
        //     }
        //     minHeap.pop();
        // }
        
        // return meetingPerformed;
    
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends