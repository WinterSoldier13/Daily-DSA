# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
        
    curr = 1
    K=0
    ans =0
    def inOrder(self, root: TreeNode):
        if(root==None):
            return
        
        self.inOrder(root.left)
        if(self.curr == self.K):
            self.ans = root.val
        self.curr-=-1
        print(root.val)
        self.inOrder(root.right)
        
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        self.K = k
        
        self.inOrder(root)
        return self.ans
        