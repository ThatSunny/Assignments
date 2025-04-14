#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    vector<int> result;         
    deque<int> dq;              

    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements out of this window (i - k)
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove all elements smaller than current from back of deque
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        // Add current index to deque
        dq.push_back(i);

        // First window completed, start adding to result
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

// Helper function
void printVector(const vector<int>& vec) {
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximums in each sliding window of size " << k << ": ";
    printVector(result);

    return 0;
}
