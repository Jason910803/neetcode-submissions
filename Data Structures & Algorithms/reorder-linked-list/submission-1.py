# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head and not head.next:
            return
        # find the midpoint of the listed list
        dummy = ListNode()
        l1_last = dummy
        slow = fast = head
        while fast and fast.next:
            l1_last = slow
            slow = slow.next
            fast = fast.next.next
        l1_last.next = None

        # reverse the list 2 and for now slow the head of list 2
        prev, curr = None, slow
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        # finally merge the two lists iteratively
        l1, l2 = head, prev
        curr = dummy
        isL1 = True
        while l1 and l2:
            if isL1:
                curr.next = l1
                l1 = l1.next
                isL1 = False
            else:
                curr.next = l2
                l2 = l2.next
                isL1 = True

            curr = curr.next
        
        curr.next = l1 or l2

        head.next = dummy.next.next