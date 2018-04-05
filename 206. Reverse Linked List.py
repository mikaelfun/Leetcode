# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        if head.next == None:
            return head
        cur = head
        while cur.next != None:
            prev = cur
            cur = cur.next
        # print (cur.val, prev.val)
        prev.next = None
        cur.next = self.reverseList(head)
        return cur

if __name__ == "__main__":
    a = Solution()
    head = ListNode(0)
    cur = head
    for i in range(1,10):
        cur.next = ListNode(i)
        cur = cur.next

    temp = a.reverseList(head)
    while temp!=None:
        print (temp.val)
        temp = temp.next
