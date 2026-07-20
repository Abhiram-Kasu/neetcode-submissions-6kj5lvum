class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = list(range(n))
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def union(a,b):
            parent[find(a)] = find(b)
        for a, b in edges:
            union(a, b)

        return len({find(i) for i in range(n)})
