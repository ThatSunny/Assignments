#include <iostream>
using namespace std;

// Function to check if a number is a power of two using bit manipulation
bool isPowerOfTwo(int num) {
    // A number is a power of two if it is greater than 0
    // num & (num - 1) is 0
    return (num > 0) && (num & (num - 1)) == 0;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPowerOfTwo(num)) {
        cout << num << " is a power of two.\n";
    } else {
        cout << num << " is not a power of two.\n";
    }

    return 0;
}
