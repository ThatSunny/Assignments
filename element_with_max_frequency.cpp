#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMaxFrequencyElement(const vector<int>& nums) {
    unordered_map<int, int> freqMap;

    for (int num : nums) {
        freqMap[num]++;
    }

    int maxFreq = 0;
    int maxElement = -1;
    for (auto& entry : freqMap) {
        if (entry.second > maxFreq) {
            maxFreq = entry.second;
            maxElement = entry.first;
        }
    }

    return maxElement;
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 3, 1, 4};

    int result = findMaxFrequencyElement(nums);

    cout << "Element with maximum frequency: " << result << endl;

    return 0;
}
