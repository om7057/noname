#include <iostream>
using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
private:
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node* head) {
        if (head->next == nullptr) {
            return true;
        }

        // Step 1 -> find Middle
        Node* middle = getMid(head);

        // Step 2 -> reverse List after Middle
        Node* temp = middle->next;
        middle->next = nullptr; // Disconnect the second half from the original list
        middle->next = reverse(temp);

        // Step 3 - Compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;

        while (head2 != nullptr) {
            if (head2->data != head1->data) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Step 4 - repeat step 2
        temp = middle->next;
        middle->next = reverse(temp);

        return true;
    }
};

// Helper function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    Solution solution;
    if (solution.isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
