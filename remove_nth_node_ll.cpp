#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node to handle edge cases (like deleting the head)
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* first = dummy;
    ListNode* second = dummy;

    // Move first pointer n+1 steps ahead so there's a gap of n between first and second
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    // Move both pointers until first reaches the end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // Remove the node
    ListNode* nodeToDelete = second->next;
    second->next = second->next->next;
    delete nodeToDelete;

    // Return the new head
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

// Helper function 
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    int n = 2; 
    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "List after removing " << n << "-th node from end: ";
    printList(head);

    return 0;
}
