# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head and not head.next:
            return

        # 1. find the midpoint of the listed list
        slow = fast = head
        prev = None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        # split the first and second half of the linked list
        prev.next = None

        # 2. reverse the second half and [slow] is the head of second list
        prev, curr = None, slow
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        # 3. finally merge the two lists iteratively
        l1, l2 = head, prev
        while l1:
            tmp1, tmp2 = l1.next, l2.next
            l1.next = l2
            l2.next = tmp1 if tmp1 else tmp2
            l1, l2 = tmp1, tmp2

        