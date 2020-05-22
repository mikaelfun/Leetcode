# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fast = head
        for i in range(n):
            fast = fast.next
        slow = head
        if fast == None:
            return head.next

        while fast.next != None:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return head