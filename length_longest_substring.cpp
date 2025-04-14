#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestUniqueSubstring(string s) {
    unordered_set<char> charSet;  // Set to store unique characters in the window
    int left = 0, maxLength = 0;

    // Traverse the string with the right pointer
    for (int right = 0; right < s.length(); right++) {
        // If the character is already in the set, move the left pointer
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }

        // Add the current character to the set
        charSet.insert(s[right]);

        // Update the maximum length of the window
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = longestUniqueSubstring(s);

    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}
