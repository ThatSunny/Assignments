#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSubsets(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, int index) {
    // Add the current subset to the result
    result.push_back(current);

    // Generate subsets by including elements from index onwards
    for (int i = index; i < nums.size(); ++i) {
        // Skip duplicates to ensure unique subsets
        if (i > index && nums[i] == nums[i - 1]) continue;

        // Include nums[i] in the current subset
        current.push_back(nums[i]);

        // Recurse to generate further subsets
        generateSubsets(nums, current, result, i + 1);

        // Backtrack by removing nums[i] from the current subset
        current.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    sort(nums.begin(), nums.end());  // Sort the array to handle duplicates
    generateSubsets(nums, current, result, 0);
    return result;
}

void printSubsets(const vector<vector<int>>& subsets) {
    for (const auto& subset : subsets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

int main() {
    vector<int> nums = {1, 2, 2};

    cout << "All subsets:\n";
    vector<vector<int>> result = subsetsWithDup(nums);
    printSubsets(result);

    return 0;
}
