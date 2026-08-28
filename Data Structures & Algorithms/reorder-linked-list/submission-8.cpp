/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        // [0, 1, 2,] [3, 4, 5]
        // [0, 1, 2, 3,] [4, 5, 6]
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }

        // use slow and fast pointer to find the second-half linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // now prev is the head of the second-half linked list
        // finally build the answer by interleaving the two linked lists
        ListNode* curr1 = head;
        ListNode* curr2 = prev;
        while (curr2) {
            ListNode* tmp1 = curr1->next;
            ListNode* tmp2 = curr2->next;
            curr1->next = curr2;
            curr2->next = tmp1;
            curr1 = tmp1;
            curr2 = tmp2;
        }

        return;
    }
};
