#include <iostream>
#include <vector>
using namespace std;

// Helper function 
void findCombinations(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int index) {
    // If target is met, save the current combination
    if (target == 0) {
        result.push_back(current);
        return;
    }

    // Try all elements starting from current index
    for (int i = index; i < candidates.size(); ++i) {
        if (candidates[i] <= target) {
            // Choose the element
            current.push_back(candidates[i]);

            // Recursive call with updated target (can reuse same number)
            findCombinations(candidates, target - candidates[i], current, result, i);

            // Backtrack: remove the last element
            current.pop_back();
        }
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    findCombinations(candidates, target, current, result, 0);
    return result;
}

// Helper function 
void printCombinations(const vector<vector<int>>& combinations) {
    for (const auto& combo : combinations) {
        cout << "[ ";
        for (int num : combo)
            cout << num << " ";
        cout << "]\n";
    }
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Unique combinations that sum to " << target << ":\n";
    printCombinations(result);

    return 0;
}
