#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

int maxSumSubarray(const vector<int>& arr, int K) {
    int n = arr.size();

    // If K is greater, return error
    if (n < K) {
        cout << "Error: K cannot be greater than the size of the array." << endl;
        return -1;
    }

    // Calculate the sum of the first K elements
    int windowSum = 0;
    for (int i = 0; i < K; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    for (int i = K; i < n; i++) {
        // Slide the window by removing the element going out and adding the element coming in
        windowSum = windowSum - arr[i - K] + arr[i];
        
        // Update maxSum if the current window sum is greater
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    // Input: array size, K, and elements
    int n, K;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    cout << "Enter the value of K: ";
    cin >> K;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to find the maximum sum of a subarray of size K
    int result = maxSumSubarray(arr, K);

    if (result != -1) {
        cout << "The maximum sum of any subarray of size " << K << " is: " << result << endl;
    }

    return 0;
}
