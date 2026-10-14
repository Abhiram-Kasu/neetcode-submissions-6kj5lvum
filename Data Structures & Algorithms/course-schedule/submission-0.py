class Solution:
    def canFinish(self, numCourses: int,
                  prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        for course, prereq in prerequisites:
            adj[course].append(prereq)

        # 0 = unchecked, 1 = in current path, 2 = fully checked
        state = [0] * numCourses

        def dfs(course):
            if state[course] == 1:
                return False  # cycle
            if state[course] == 2:
                return True

            state[course] = 1
            for prereq in adj[course]:
                if not dfs(prereq):
                    return False

            state[course] = 2
            return True

        return all(dfs(course) for course in range(numCourses))