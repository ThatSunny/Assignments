#include <iostream>
using namespace std;

int expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // Length of the palindrome
}

string longestPalindrome(string s) {
    if (s.empty()) return "";

    int start = 0, maxLength = 1;

    // Iterate through each character in the string
    for (int i = 0; i < s.length(); i++) {
        // Check for odd-length palindrome (single character center)
        int len1 = expandAroundCenter(s, i, i);
        // Check for even-length palindrome (pair of characters center)
        int len2 = expandAroundCenter(s, i, i + 1);
        
        // Take the maximum of the two
        int len = max(len1, len2);

        // If we found a longer palindrome, update the result
        if (len > maxLength) {
            maxLength = len;
            start = i - (len - 1) / 2; // Adjust the start index
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = longestPalindrome(s);

    cout << "The longest palindromic substring is: " << result << endl;

    return 0;
}
