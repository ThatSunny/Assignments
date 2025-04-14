#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* a = headA;
    ListNode* b = headB;

    // Traverse both lists
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

// Helper function
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {

    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(9);

    // List A
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = intersect;

    // List B
    ListNode* headB = new ListNode(3);
    headB->next = intersect;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    ListNode* result = getIntersectionNode(headA, headB);

    if (result) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
