'''Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
'''
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # reverse it and see if they are equal
        valArr = []
        temp = head
        while (temp != None):
            valArr.append(temp.val)
            temp = temp.next
        i = 0
        j = len(valArr) - 1
        while i<j:
            if valArr[i] != valArr[j]:
                return False
            i+=1
            j-=1
        return True

if __name__ == "__main__":
    a = Solution()
    head = ListNode(0)
    cur = head
    for i in range(1,10):
        cur.next = ListNode(i)
        cur = cur.next
    for j in range(0,10):
        cur.next = ListNode(9-j)
        cur = cur.next


    print (a.isPalindrome(head))

