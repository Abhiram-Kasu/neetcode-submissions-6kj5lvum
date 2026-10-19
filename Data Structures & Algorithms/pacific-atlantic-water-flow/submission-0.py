class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []

        rows, cols = len(heights), len(heights[0])
        pacific = set()
        atlantic = set()

        def dfs(x, y, reachable):
            if (x, y) in reachable:
                return

            reachable.add((x, y))

            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nx, ny = x + dx, y + dy

                if (
                    0 <= nx < rows
                    and 0 <= ny < cols
                    and heights[nx][ny] >= heights[x][y]
                ):
                    dfs(nx, ny, reachable)

        # Left and right borders
        for x in range(rows):
            dfs(x, 0, pacific)
            dfs(x, cols - 1, atlantic)

        # Top and bottom borders
        for y in range(cols):
            dfs(0, y, pacific)
            dfs(rows - 1, y, atlantic)

        return [[x, y] for x, y in pacific & atlantic]