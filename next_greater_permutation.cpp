#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int k = -1;

    // Find the largest index k such that nums[k] < nums[k + 1]
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            k = i;
            break;
        }
    }

    // If no such index is found, the current permutation is the largest
    if (k == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Find the largest index l such that nums[k] < nums[l]
    int l = -1;
    for (int i = n - 1; i > k; i--) {
        if (nums[i] > nums[k]) {
            l = i;
            break;
        }
    }

    // Swap nums[k] and nums[l]
    swap(nums[k], nums[l]);

    // Reverse the sequence from nums[k + 1] to the end
    reverse(nums.begin() + k + 1, nums.end());
}

int main() {
    vector<int> nums;
    int n, temp;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }

    nextPermutation(nums);
    
    cout << "The next permutation is: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
