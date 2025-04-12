class Solution {
    public:
        double myPowUtil(double x, long long n) {
            // Base case: x^0 = 1
            if (n == 0) return 1;
            
            // Divide step (exponentiation by squaring)
            double half = myPowUtil(x, n / 2);
    
            // If n is even, return half * half
            if (n % 2 == 0) return half * half;
    
            // If n is odd, return x * (half * half)
            return x * half * half;
        }
    
        double myPow(double x, int n) {
            long long N = n;  // Convert to long long to handle INT_MIN safely
            
            // Handle negative exponent case
            if (N < 0) {
                x = 1 / x;
                N = -N;
            }
    
            return myPowUtil(x, N);
        }
    };
    