
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        // Approach 2 - double s string and find whether goal is present it in
        // or not s + s: Concatenating the string with itself creates a "doubled
        // string."
        // For example:
        // If s = "abcde", then s + s = "abcdeabcde"
        // Any valid rotation of s must appear as a substring within this
        // doubled string. For example: If goal = "cdeab" (a rotation of
        // "abcde"), "abcdeabcde" contains "cdeab".

        return s.length() == goal.length() && (s+s).find(goal) != -1;


        // Approach 1
        //  Check lengths first
        //  if (s.length() != goal.length()) {
        //      return false;
        //  }

        // int size = s.length();
        // string temp = s; // Correct initialization

        // for (int i = 0; i < size; i++) {
        //     temp = temp.substr(1) + temp[0]; // Rotate left
        //     if (temp == goal) {
        //         return true;
        //     }
        // }
        // return false;
    }
};
