class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        for c, pre in prerequisites:
            adj[c].append(pre)

        # 0 = unchecked, 1 = in current path, 2 = completed
        visited = [0] * numCourses
        order = []

        def dfs(course):
            if visited[course] == 1:
                return False  # cycle
            if visited[course] == 2:
                return True

            visited[course] = 1

            for pre in adj[course]:
                if not dfs(pre):
                    return False

            visited[course] = 2
            order.append(course)
            return True

        for course in range(numCourses):
            if not dfs(course):
                return []

        return order
        
