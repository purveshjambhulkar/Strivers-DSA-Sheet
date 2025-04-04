class Solution {
    public:
        const int MOD = 1e9 + 7;
    
        long long pow_mod(long long base, long long exp) {
            long long result = 1;
            base = base % MOD;
            while (exp > 0) {
                if (exp % 2 == 1) {
                    result = (result * base) % MOD;
                }
                base = (base * base) % MOD;
                exp = exp / 2;
            }
            return result;
        }
    
        int countGoodNumbers(long long n) {
            long long even_indices = (n + 1) / 2;
            long long odd_indices = n / 2;
            long long even_choices = pow_mod(5, even_indices);
            long long odd_choices = pow_mod(4, odd_indices);
            return (even_choices * odd_choices) % MOD;
        }
    };