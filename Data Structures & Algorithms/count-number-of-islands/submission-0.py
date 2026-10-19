class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(x,y): 
            if not (0 <= x < len(grid)) or not (0 <= y < len(grid[0])):
                return
            if grid[x][y] == "0":
                return

            grid[x][y] = "0"
            dfs(x+1,y)
            dfs(x-1,y)
            dfs(x,y+1)
            dfs(x,y-1)

        counter = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    counter += 1
                    dfs(i,j)
        return counter


            
        