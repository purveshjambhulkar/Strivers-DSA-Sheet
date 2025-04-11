
#include <iostream>
using namespace std;

int findXOR(int n) {
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

int findXORRange(int l, int r) {
    return findXOR(l - 1) ^ findXOR(r);
}

int main() {
    int l, r;
    cout << "Enter the lower limit of the range: ";
    cin >> l;
    cout << "Enter the upper limit of the range: ";
    cin >> r;
    cout << "XOR of numbers in the range [" << l << ", " << r << "] is: " << findXORRange(l, r);
    return 0;
}
