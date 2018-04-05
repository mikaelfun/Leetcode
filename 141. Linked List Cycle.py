'''
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # Floyd Cycle Detection Algorithm ,slow goes 1 step, fast goes 2 steps
        # if there is any cycle, slow and fast will eventually meet
        slow, fast = head, head
        while slow!= None and fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

if __name__ == "__main__":
    a = Solution()
    head = ListNode(0)
    cur = head
    for i in range(1,10):
        cur.next = ListNode(i)
        cur = cur.next

    print(a.hasCycle(head))

