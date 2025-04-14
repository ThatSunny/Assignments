#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Function to find the top K frequent elements in an array
vector<int> topKFrequent(vector<int>& nums, int k) {
    // Count the frequency of each element in the array
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // Use a priority queue (max-heap) to find the top K frequent elements
    priority_queue<pair<int, int>> maxHeap;
    for (auto& entry : freqMap) {
        maxHeap.push({entry.second, entry.first});
    }

    // Extract the top K frequent elements
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
