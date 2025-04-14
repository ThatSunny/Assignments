#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(string& s, int start, vector<string>& result) {
    // If we've considered all characters, store the permutation
    if (start == s.length()) {
        result.push_back(s);
        return;
    }

    // Iterate and swap each character with the start
    for (int i = start; i < s.length(); i++) {
        // Swap current index with start index
        swap(s[start], s[i]);

        // Recurse with next character
        generatePermutations(s, start + 1, result);

        // Backtrack
        swap(s[start], s[i]);
    }
}

int main() {
    
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> result;
    generatePermutations(s, 0, result);

    cout << "All permutations are: \n";
    for (const string& perm : result) {
        cout << perm << endl;
    }

    return 0;
}
