#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
    // If the current permutation is of the same length as the original array
    // add it to the result
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        // Skip the used elements or duplicates to avoid generating same permutations
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) continue;

        // Mark the current element as used
        used[i] = true;
        current.push_back(nums[i]);

        // Recurse to generate the next part of the permutation
        generatePermutations(nums, current, used, result);

        // Backtrack by unmarking the current element and removing it from the current permutation
        used[i] = false;
        current.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);

    // Sort the array to handle duplicates
    sort(nums.begin(), nums.end());

    generatePermutations(nums, current, used, result);
    return result;
}

void printPermutations(const vector<vector<int>>& permutations) {
    for (const auto& perm : permutations) {
        cout << "[ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

int main() {
    vector<int> nums = {1, 1, 2};

    cout << "All unique permutations:\n";
    vector<vector<int>> result = permuteUnique(nums);
    printPermutations(result);

    return 0;
}
