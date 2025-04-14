#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    // Attach the remaining nodes of whichever list is not empty
    if (l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    // The head of merged list is next of dummy node
    return dummy->next;
}

// Function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createNode(int val) {
    return new ListNode(val);
}

int main() {
    ListNode* l1 = createNode(1);
    l1->next = createNode(2);
    l1->next->next = createNode(4);

    ListNode* l2 = createNode(1);
    l2->next = createNode(3);
    l2->next->next = createNode(4);

    // Merging
    ListNode* mergedList = mergeTwoLists(l1, l2);

    cout << "Merged Linked List: ";
    printList(mergedList);

    return 0;
}
