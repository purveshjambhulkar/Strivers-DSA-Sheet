#include <iostream>
using namespace std;

bool isOdd(int n) {
    return (n & 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isOdd(n))
        cout << n << " is Odd" << endl;
    else
        cout << n << " is Even" << endl;

    return 0;
}
