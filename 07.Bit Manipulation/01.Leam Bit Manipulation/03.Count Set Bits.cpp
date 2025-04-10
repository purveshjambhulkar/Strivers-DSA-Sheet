#include <iostream>

using namespace std;

// Function to count set bits using Brian Kernighan’s Algorithm
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); // Unset the last set bit
        count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    int result = countSetBits(n);
    cout << "The number of set bits in " << n << " is: " << result << endl;
    
    return 0;
}
