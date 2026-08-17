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
        slow = fast = head
        prev = None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        # split the first and second half of the linked list
        prev.next = None

        # reverse the list 2 and for now slow the head of list 2
        prev, curr = None, slow
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        # finally merge the two lists iteratively
        l1, l2 = head, prev
        while l1:
            tmp1 = l1.next
            tmp2 = l2.next

            l1.next = l2
            l2.next = tmp1 if tmp1 else tmp2

            l1 = tmp1
            l2 = tmp2

        