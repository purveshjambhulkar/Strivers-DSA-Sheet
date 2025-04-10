#include <iostream>

using namespace std;

// Function to check if the i-th bit is set
bool isBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}

// Function to set the i-th bit
int setBit(int n, int i) {
    return n | (1 << i);
}

// Function to clear the i-th bit
int clearBit(int n, int i) {
    return n & ~(1 << i);
}

// Function to toggle the i-th bit
int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

// Function to unset the last set bit (set the rightmost 1-bit to 0)
int unsetLastSetBit(int n) {
    return n & (n - 1);
}

// Function to check if a number is a power of 2
bool isPowerOf2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int n, i, choice;
    
    cout << "Enter a number: ";
    cin >> n;
    
    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Check if a bit is set\n";
        cout << "2. Set a bit\n";
        cout << "3. Clear a bit\n";
        cout << "4. Toggle a bit\n";
        cout << "5. Unset last set bit\n";
        cout << "6. Check if number is power of 2\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter bit position to check (0-indexed): ";
                cin >> i;
                if (isBitSet(n, i)) {
                    cout << "The " << i << "-th bit is set.\n";
                } else {
                    cout << "The " << i << "-th bit is not set.\n";
                }
                break;

            case 2:
                cout << "Enter bit position to set (0-indexed): ";
                cin >> i;
                n = setBit(n, i);
                cout << "The new number is: " << n << endl;
                break;

            case 3:
                cout << "Enter bit position to clear (0-indexed): ";
                cin >> i;
                n = clearBit(n, i);
                cout << "The new number is: " << n << endl;
                break;

            case 4:
                cout << "Enter bit position to toggle (0-indexed): ";
                cin >> i;
                n = toggleBit(n, i);
                cout << "The new number is: " << n << endl;
                break;

            case 5:
                n = unsetLastSetBit(n);
                cout << "The new number after unsetting last set bit is: " << n << endl;
                break;

            case 6:
                if (isPowerOf2(n)) {
                    cout << n << " is a power of 2.\n";
                } else {
                    cout << n << " is NOT a power of 2.\n";
                }
                break;

            case 7:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}
