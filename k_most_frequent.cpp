#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;

    // Count frequencies
    for (int num : nums) {
        freqMap[num]++;
    }

    // Push elements into a max heap (priority queue)
    priority_queue<pair<int, int>> maxHeap; // {frequency, number}

    for (auto& entry : freqMap) {
        maxHeap.push({entry.second, entry.first});
    }

    // Extract top k elements
    vector<int> result;
    for (int i = 0; i < k && !maxHeap.empty(); ++i) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
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
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    printVector(result);

    return 0;
}