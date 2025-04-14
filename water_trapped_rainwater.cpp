#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    // Arrays to store the maximum height to the left and right of each element
    vector<int> maxLeft(n), maxRight(n);

    // Fill the maxLeft array
    maxLeft[0] = height[0];
    for (int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i - 1], height[i]);
    }

    // Fill the maxRight array
    maxRight[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i + 1], height[i]);
    }

    // Calculate the total water trapped
    int totalWater = 0;
    for (int i = 0; i < n; i++) {
        totalWater += min(maxLeft[i], maxRight[i]) - height[i];
    }

    return totalWater;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int result = trap(height);
    
    cout << "Total water trapped: " << result << " units" << endl;

    return 0;
}
