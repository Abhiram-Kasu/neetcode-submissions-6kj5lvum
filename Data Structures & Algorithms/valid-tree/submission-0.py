class Solution:

    parent = []
    

    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
        parent = list(range(n))
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(a,b):
            parent[find(a)] = find(b)

        for a,b in edges:
            #check if atleast one edge is not in the union
            if find(a) == find(b):
                return False
            #union them both
            union(a,b)
        return True




        