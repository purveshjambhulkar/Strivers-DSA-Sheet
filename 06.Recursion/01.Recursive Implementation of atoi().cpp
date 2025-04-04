class Solution {
    public:
        int myAtoiUtil(string s, int sign, long long& ans, int ind) {
            // Base case: Stop if out of bounds or non-digit
            if (ind == s.length() || !isdigit(s[ind])) {
                return sign * ans;
            }
    
            // Extract digit
            int digit = s[ind] - '0';
    
            // Check overflow before updating ans
            if (sign == 1 && ans > (INT_MAX - digit) / 10) {
                return INT_MAX;
            }
            if (sign == -1 && ans > (-(long long)INT_MIN - digit) / 10) {
                return INT_MIN;
            }
    
            // Update ans
            ans = ans * 10 + digit;
    
            // Recurse to next index
            return myAtoiUtil(s, sign, ans, ind + 1);
        }
        int myAtoi(string s) {
            // Recursive Approach
    
            int sign = 1;
            long long ans = 0;
    
            // Skip whitespaces
            int i = 0;
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
    
            // Check sign
            if (i < s.length() && s[i] == '-') {
                sign = -1;
                i++;
            } else if (i < s.length() && s[i] == '+') {
                sign = 1;
                i++;
            }
    
            // Call recursive function with correct index
            return myAtoiUtil(s, sign, ans, i);
    
            // int sign = 1;
            // long long ans = 0;
    
            // // skip whitespaces
            // int i = 0;
            // while (s[i] == ' ') {
            //     i++;
            // }
    
            // // sign check
            // if ((s[i]) == '-') {
            //     sign = -1;
            //     i++;
            // } else if (s[i] == '+') {
            //     sign = +1;
            //     i++;
            // }
    
            // for (; i < s.length(); i++) {
            //     if (isdigit(s[i])) {
            //         ans = ans * 10 + (s[i] - '0');
            //         // Handle overflow and underflow immediately
            //         if (sign == 1 && ans > INT_MAX) {
            //             return INT_MAX;
            //         }
            //         if (sign == -1 && -ans < INT_MIN) {
            //             return INT_MIN;
            //         }
            //     } else {
            //         break;
            //     }
            // }
    
            // return ans * sign;
        }
    };