#include <iostream>
using namespace std;

class TwoStacks {
private:
    int* arr;      // Array to hold both stacks
    int size;      // Total size of the array
    int top1;      // Top pointer for Stack 1
    int top2;      // Top pointer for Stack 2

public:
    // Constructor
    TwoStacks(int n) {
        size = n;
        arr = new int[size];
        top1 = -1;         // Stack 1 starts from beginning
        top2 = size;       // Stack 2 starts from end
    }

    // Push into Stack 1
    void push1(int x) {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack Overflow in Stack 1\n";
        }
    }

    // Push into Stack 2
    void push2(int x) {
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack Overflow in Stack 2\n";
        }
    }

    // Pop from Stack 1
    int pop1() {
        if (top1 >= 0) {
            int val = arr[top1];
            top1--;
            return val;
        } else {
            cout << "Stack Underflow in Stack 1\n";
            return -1;
        }
    }

    // Pop from Stack 2
    int pop2() {
        if (top2 < size) {
            int val = arr[top2];
            top2++;
            return val;
        } else {
            cout << "Stack Underflow in Stack 2\n";
            return -1;
        }
    }
};

int main() {
    TwoStacks ts(10); // Array of size 10

    // Pushing elements to both stacks
    ts.push1(5);
    ts.push1(10);
    ts.push2(20);
    ts.push2(30);

    // Popping elements
    cout << "Popped from Stack 1: " << ts.pop1() << endl;  // 10
    cout << "Popped from Stack 2: " << ts.pop2() << endl;  // 30

    return 0;
}