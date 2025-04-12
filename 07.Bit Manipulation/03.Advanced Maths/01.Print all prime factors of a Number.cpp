#include <iostream>
using namespace std;

void primeFactors(int n) {
    
    for(int i = 2; i < sqrt(n) + 1; i++) {
        while(n % i == 0) {
            cout << i << " ";
            while(n % i == 0) {
                n /= i;
            }
        }
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Prime factors are: ";
    primeFactors(num);
    return 0;
}