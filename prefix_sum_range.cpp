#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_sum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    return prefix;
}

int range_sum(const vector<int>& prefix, int L, int R) {
    if (L == 0) {
        return prefix[R];
    } else {
        return prefix[R] - prefix[L-1];
    }
}

int main() {
    vector<int> arr = {2, 4, 7, 3, 8, 1};
    int L = 1;
    int R = 4;
    vector<int> prefix = prefix_sum(arr);

    int sum_in_range = range_sum(prefix, L, R);

    cout << "Sum of elements from index " << L << " to " << R << " is: " << sum_in_range << endl;
    return 0;
}
