#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // nums1 is the smaller array
    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }

    int n = nums1.size();
    int m = nums2.size();
    int low = 0, high = n;

    while (low <= high) {
        int partition1 = (low + high) / 2;
        int partition2 = (n + m + 1) / 2 - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == n) ? INT_MAX : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == m) ? INT_MAX : nums2[partition2];

        // Check if we found correct partition
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // If total number of elements is odd
            if ((n + m) % 2 == 1) {
                return max(maxLeft1, maxLeft2);
            } else {
                // If total number of elements is even
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }
        }
        // Adjust binary search bounds based on partition condition
        else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        } else {
            low = partition1 + 1;
        }
    }

    return 0.0;
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);

    cout << "The median is: " << median << endl;

    return 0;
}
