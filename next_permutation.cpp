#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Find the first index 'i' such that nums[i] < nums[i + 1]
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // If such an index exists, find index 'j' to swap with
    if (i >= 0) {
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        // Swap nums[i] and nums[j]
        swap(nums[i], nums[j]);
    }

    // Reverse the subarray from i + 1 to end
    reverse(nums.begin() + i + 1, nums.end());
}

// Helper function 
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3};

    cout << "Original array: ";
    printArray(nums);

    nextPermutation(nums);

    cout << "Next permutation: ";
    printArray(nums);

    return 0;
}