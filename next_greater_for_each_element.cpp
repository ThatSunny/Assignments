#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        // Check if current element is greater than the element at the top of the stack
        while (!s.empty() && nums[s.top()] < nums[i]) {
            int index = s.top();
            s.pop();
            result[index] = nums[i];  // Update the result with the next greater element
        }
        s.push(i);  // Push current index onto the stack
    }

    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    
    vector<int> result = nextGreaterElement(nums);

    cout << "Next greater element for each element: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
