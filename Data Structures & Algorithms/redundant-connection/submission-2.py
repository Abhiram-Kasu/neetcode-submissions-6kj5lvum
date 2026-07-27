class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        #find the cycle in the acyclic graph
        # leaning towards using union find? 
        # for each edge in the edges

        parent = list(range(len(edges)+1))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def union(a,b) -> bool: 
            rootA, rootB = find(a), find(b)
            if rootA == rootB:
                return False
            parent[rootB] = rootA;
            return True

        lastEdge = []

        for a,b in edges:
            if not union(a,b):
                lastEdge = [a,b]
        
        return lastEdge

        



        