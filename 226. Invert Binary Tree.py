"""
Invert a binary tree.
     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None

        newRoot = TreeNode(root.val)
        tempright = root.right
        templeft = root.left
        if not templeft and not tempright:
            return newRoot
        elif not tempright:
            newRoot.right = self.invertTree(templeft)
        elif not templeft:
            newRoot.left = self.invertTree(tempright)
        else:
            newRoot.right = self.invertTree(templeft)
            newRoot.left = self.invertTree(tempright)
        return newRoot

if __name__ == "__main__":
    a = Solution()
    root = TreeNode(11)
    print (a.invertTree(root).val)
