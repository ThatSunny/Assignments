#include <iostream>
using namespace std;

bool isPalindrome(int num) {
    // Edge case: negative numbers are not palindromes
    if (num < 0) return false;

    // Edge case: single digit numbers are always palindromes
    if (num >= 0 && num < 10) return true;

    int original = num;
    int reversedHalf = 0;

    // Reverse the second half of the number
    while (num > reversedHalf) {
        reversedHalf = reversedHalf * 10 + num % 10;
        num /= 10;
    }

    // If the number has an odd number of digits
    // ignore the middle digit by dividing reversedHalf by 10
    return num == reversedHalf || num == reversedHalf / 10;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome.\n";
    } else {
        cout << num << " is not a palindrome.\n";
    }

    return 0;
}
