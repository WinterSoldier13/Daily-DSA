class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        summary = []
        for item in matrix:
            summary += item
        
        print(summary)
        return sorted(summary)[k-1]