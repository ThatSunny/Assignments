#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(const vector<int>& arr) {
    int totalSum = 0;
    int leftSum = 0;
    
    // Calculate total sum of the array
    for (int num : arr) {
        totalSum += num;
    }

    // Traverse the array and check for equilibrium index
    for (int i = 0; i < arr.size(); i++) {
        int rightSum = totalSum - leftSum - arr[i];

        // If left sum equals right sum, we found the equilibrium index
        if (leftSum == rightSum) {
            return i;  // Return the first equilibrium index found
        }

        // Update left sum for the next iteration
        leftSum += arr[i];
    }

    // If no equilibrium index is found
    return -1;
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

    int index = findEquilibriumIndex(arr);

    if (index != -1) {
        cout << "Equilibrium index found at position: " << index << endl;
    } else {
        cout << "No equilibrium index found." << endl;
    }

    return 0;
}
