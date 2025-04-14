#include <iostream>
#include <vector>
using namespace std;

bool canBeSplitEqually(const vector<int>& arr) {
    int totalSum = 0;

    //Calculate total sum of the array
    for (int num : arr) {
        totalSum += num;
    }

    int leftSum = 0;

    // Traverse the array and keep updating leftSum
    for (int i = 0; i < arr.size() - 1; i++) {
        leftSum += arr[i];
        int rightSum = totalSum - leftSum;

        if (leftSum == rightSum) {
            return true; // Found a split
        }
    }

    return false; // No split point found
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (canBeSplitEqually(arr)) {
        cout << "Yes, the array can be split into two parts with equal sum." << endl;
    } else {
        cout << "No, the array cannot be split into two parts with equal sum." << endl;
    }

    return 0;
}
