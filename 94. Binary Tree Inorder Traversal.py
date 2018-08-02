'''
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # 1st: recursive
#         if not root:
#             return []
#         else:
#             return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)

        # 2nd: iterative
        nodeStack = []
        if not root:
            return []
        temp = root
        nodeStack.append(temp)
        myDict = {}
        myDict[root] = True
        presize = 0
        while presize != len(nodeStack):
            tempStack = []
            for i in range(len(nodeStack)):
                if nodeStack[i].left != None and nodeStack[i].left not in myDict:
                    tempStack.append(nodeStack[i].left)
                    myDict[nodeStack[i].left] = True
                tempStack.append(nodeStack[i])
                if nodeStack[i].right!= None and nodeStack[i].right not in myDict:
                    tempStack.append(nodeStack[i].right)
                    myDict[nodeStack[i].right] = True
            presize = len(nodeStack)
            nodeStack = tempStack
            print (presize, len(nodeStack))
        output = []
        for each in nodeStack:
            output.append(each.val)
        return output

if __name__ == '__main__':
    a = Solution
    root = TreeNode(1)
    root.right = TreeNode(3)
    root.right.left = TreeNode(2)
    print (a.inorderTraversal(a,root ))

    # stack = [root]
    # stack = [root.left, root.right]   list = [root]
    # stack = [root.left, root.right
