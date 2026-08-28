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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1, 2, 3, 4, 5
        ListNode dummy;
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // now slow points to the previous node that would be removed
        ListNode* node_to_delete = slow->next;
        slow->next = slow->next->next;
        delete node_to_delete;

        return dummy.next;
    }
};
