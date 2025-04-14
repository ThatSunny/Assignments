#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    // Initialize the max and min products to the first element
    int maxProduct = nums[0];
    int minProduct = nums[0];
    int result = nums[0];

    // Traverse the array starting from the second element
    for (int i = 1; i < nums.size(); i++) {
        // If the current element is negative, swap maxProduct and minProduct
        if (nums[i] < 0) {
            swap(maxProduct, minProduct);
        }
        
        // Update maxProduct and minProduct
        maxProduct = max(nums[i], maxProduct * nums[i]);
        minProduct = min(nums[i], minProduct * nums[i]);

        // Update the result to be the maximum of the current result and maxProduct
        result = max(result, maxProduct);
    }

    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    
    int result = maxProduct(nums);

    cout << "Maximum product subarray: " << result << endl;
    
    return 0;
}
