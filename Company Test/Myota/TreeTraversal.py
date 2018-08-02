import os
from os.path import join, getsize

'''
1. Traverse a tree
'''


class TreeNode:
    def __init__(self, x = 0):
        self.val = x
        self.left = None
        self.right = None

    def add(self, node):
        if node.val > self.val:
            if not self.right:
                self.right = node
            else:
                self.right.add(node)
        elif node.val == self.val:
            print ("Node Exists!")
        else:
            if not self.left:
                self.left = node
            else:
                self.left.add(node)

'''
Traverse a tree recursively
pre-order
'''


def tree_traversal_rec(root):
    if not root:
        return None
    print (root.val)
    tree_traversal_rec(root.left)
    tree_traversal_rec(root.right)

'''
Traverse a tree iteratively
pre-order
'''


def tree_traversal_iter(root):
    if not root:
        return None
    stack = [root]
    while stack:
        top = stack[0]
        print(top.val)
        stack = stack[1:]
        if top.right:
            stack.insert(0, top.right)
        if top.left:
            stack.insert(0, top.left)

if __name__ == "__main__":
    root = None
    node = None
    while True:
        print("enter tree node")
        try:
            num = input()
            if num == "":
                print("traverse iteratively: ")
                tree_traversal_iter(root)
                print("traverse recursively: ")
                tree_traversal_rec(root)
                break
            num = int(num)
            if not root:
                root = TreeNode(num)
            else:
                node = TreeNode(num)
                root.add(node)
        except:
            print ("invalid input, please enter numbers")

# treeTraversalIter(root)

