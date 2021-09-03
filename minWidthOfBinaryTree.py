class Solution(object):
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # Logic: Any binary tree can be represented by an array. If root is represented by arrray index 1, then its left child is represented by 2, right by 3. If node index is i, then left index is 2*i and right node index is 2*i+1.
        #     1
        #   2   3
        #  4 5 6  7
        # [1, 2, 3, 4, 5, 6, 7] is the array rep of the tree.
        
        if not root:
            return 0        
        
        queue = collections.deque()
        queue.append((root, 1))
        self.ans = 0
        while queue:
            length = len(queue)
            min_node_index = None
            max_node_index = 1
            while length > 0:
                node, node_index = queue.popleft()
                if min_node_index is None:
                    min_node_index = node_index
                max_node_index = node_index
                if node.left:
                    queue.append((node.left, node_index * 2))
                if node.right:
                    queue.append((node.right, node_index * 2 + 1))
                length -= 1
            
            self.ans = max(self.ans, max_node_index - min_node_index + 1)
        return self.ans