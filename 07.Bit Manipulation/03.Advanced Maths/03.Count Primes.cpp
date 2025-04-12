class Solution {
    public:
        bool isPrime(int n) {
            int count = 0;
            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    if (i * i == n)
                        count += 1;  // Perfect square
                    else
                        count += 2;  // Count both i and n/i
                }
                if (count > 2) {
                    return false;
                }
            }
            return true;
        }
    
        int countPrimes(int n) {
            //Approach 2- Sieve of Eratosthenes
    
            int count = 0;
            vector<bool> prime(n+1 , true);
    
            prime[0] = prime[1] = false;
    
            for(int i = 2 ; i < n ; i++){
                if(prime[i]){
                    count++;
                    for(int j = 2*i ; j < n ; j=j+i ){
                        prime[j] = 0;
                    } 
                }
            }
            return count;
        
            
    
    
            // Approach 1 - Brute Force
    
            // int count = 0;
            // for (int i = 2; i < n; i++) {
            //     if (isPrime(i)) {
            //         count++;
            //     }
            // }
            // return count;
        }
    };