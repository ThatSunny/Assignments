#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Element {
    int value;
    int row;
    int col;
    
    Element(int v, int r, int c) : value(v), row(r), col(c) {}
    
    // Overload the comparison operator to create a min-heap
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    
    // Min-heap to store the elements with their row and column indices
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    
    // Push the first element of each row into the min-heap
    for (int i = 0; i < n; i++) {
        minHeap.push(Element(matrix[i][0], i, 0));
    }
    
    // Extract the minimum element K times
    Element current(0, 0, 0);
    for (int i = 0; i < k; i++) {
        // Extract the minimum element from the heap
        current = minHeap.top();
        minHeap.pop();
        
        // If there is another element in the same row, push it into the heap
        if (current.col + 1 < n) {
            minHeap.push(Element(matrix[current.row][current.col + 1], current.row, current.col + 1));
        }
    }
    
    // The K-th smallest element will be in the 'current' variable
    return current.value;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    
    int k = 8;
    int result = kthSmallest(matrix, k);
    
    cout << "The " << k << "-th smallest element is: " << result << endl;
    
    return 0;
}
