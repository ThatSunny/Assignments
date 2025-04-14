#include <iostream>
using namespace std;

int countOnesInBinary(int num) {
    int count = 0;
    while (num > 0) {
        // Remove the rightmost 1 bit
        num = num & (num - 1);
        count++;
    }
    return count;
}

// Function to count the total number of 1s in binary representation from 0 to n
int countTotalOnes(int n) {
    int totalCount = 0;
    for (int i = 0; i <= n; i++) {
        totalCount += countOnesInBinary(i);
    }
    return totalCount;
}

int main() {
    int n;
    cout << "Enter a number n: ";
    cin >> n;

    int result = countTotalOnes(n);

    cout << "The total number of 1s in binary representation from 0 to " << n << " is: " << result << endl;

    return 0;
}
