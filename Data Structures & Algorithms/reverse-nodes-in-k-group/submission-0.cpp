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
private:
    ListNode* getKthNode(ListNode* node, int k) {
        while (node != nullptr && k > 0) {
            node = node->next;
            k--;
        }
        return node;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy{0, head};
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* groupStart = groupPrev->next;
            ListNode* kth = getKthNode(groupPrev, k);
            if (kth == nullptr) {
                break;
            }
            ListNode* groupNext = kth->next;

            // start reverse
            ListNode* prev = groupNext;
            ListNode* curr = groupStart;
            while (curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            groupPrev->next = kth;
            groupPrev = groupStart;
        }

        return dummy.next;
    }
};
