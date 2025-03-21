class Solution {
    public:
        int myAtoi(string s) {
            int sign = 1;
            long long ans = 0;
    
            // skip whitespaces
            int i = 0;
            while (s[i] == ' ') {
                i++;
            }
    
            // sign check
            if ((s[i]) == '-') {
                sign = -1;
                i++;
            } else if (s[i] == '+') {
                sign = +1;
                i++;
            }
    
            for (; i < s.length(); i++) {
                if (isdigit(s[i])) {
                    ans = ans * 10 + (s[i] - '0');
                    // Handle overflow and underflow immediately
                    if (sign == 1 && ans > INT_MAX) {
                        return INT_MAX;
                    }
                    if (sign == -1 && -ans < INT_MIN) {
                        return INT_MIN;
                    }
                } else {
                    break;
                }
            }
    
            return ans * sign;
        }
    };