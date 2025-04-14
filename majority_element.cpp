#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(const vector<int>& arr) {
    int candidate = -1;  // Candidate for majority element
    int count = 0;

    // Find the candidate for majority element using Boyer-Moore Voting Algorithm
    for (int num : arr) {
        if (count == 0) {
            candidate = num;  // Set the candidate
        }
        // Increment or decrement the count based on whether the current number matches the candidate
        count += (num == candidate) ? 1 : -1;
    }

    // Verify if the candidate is actually the majority element
    int countCandidate = 0;
    for (int num : arr) {
        if (num == candidate) {
            countCandidate++;
        }
    }

    // If the candidate appears more than n/2 times, return it, otherwise return -1
    if (countCandidate > arr.size() / 2) {
        return candidate;
    } else {
        return -1;  // No majority element
    }
}

int main() {
    // array size and elements
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the function to find the majority element
    int result = findMajorityElement(arr);

    if (result == -1) {
        cout << "No majority element found.\n";
    } else {
        cout << "The majority element is: " << result << endl;
    }

    return 0;
}
