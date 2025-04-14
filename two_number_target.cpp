#include <iostream>
#include <vector>
using namespace std;

bool findTwoSum(const vector<int>& arr, int target) {
    int left = 0;  // Initialize left pointer
    int right = arr.size() - 1;  // Initialize right pointer

    // Traverse the array using two pointers
    while (left < right) {
        int currentSum = arr[left] + arr[right];

        // Check if the current sum equals the target
        if (currentSum == target) {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")\n";
            return true;
        } 
        // Adjust the pointers based on the current sum
        else if (currentSum < target) {
            left++;  // Move the left pointer to the right
        } else {
            right--;  // Move the right pointer to the left
        }
    }

    return false;  // No pair found
}

int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (!findTwoSum(arr, target)) {
        cout << "No pair found that adds up to the target.\n";
    }

    return 0;
}
