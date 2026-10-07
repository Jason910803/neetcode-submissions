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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *curr = &dummy;
        int carry = 0;

        while (l1 && l2) {
            int num = l1->val + l2->val + carry;
            curr->next = new ListNode(num % 10);
            carry = num / 10;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int num = l1->val + carry;
            curr->next = new ListNode(num % 10);
            carry = num / 10;
            curr = curr->next;
            l1 = l1->next;
        }
        
        while (l2) {
            int num = l2->val + carry;
            curr->next = new ListNode(num % 10);
            carry = num / 10;
            curr = curr->next;
            l2 = l2->next;
        }

        if (carry) {
            curr->next = new ListNode(1);
        }

        return dummy.next;
    }
};
