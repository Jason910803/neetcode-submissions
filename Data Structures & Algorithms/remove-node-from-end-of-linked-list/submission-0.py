# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # first calculate the len of the list
        llen = 0
        curr = head
        while curr:
            llen += 1
            curr = curr.next
        
        index = llen - n
        curr, prev = head, None
        for _ in range(index):
            prev = curr
            curr = curr.next
        
        # remove the first node
        if prev == None:
            return head.next
        
        prev.next = curr.next
        return head