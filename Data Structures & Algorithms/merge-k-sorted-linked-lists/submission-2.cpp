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
    struct CompareNode {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* curr = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty()) {
            ListNode* tmp = pq.top();
            pq.pop();
            if (tmp->next) {
                pq.push(tmp->next);
            }
            curr->next = tmp;
            curr = curr->next;
        }

        return dummy.next;
    }
};
