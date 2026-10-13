class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        start_row, end_row = 0, len(matrix)-1

        while start_row <= end_row:
            middle_row_i = (start_row + end_row) // 2
            middle_row = matrix[middle_row_i]
            
            if middle_row[0] <= target <= middle_row[-1]:
                return target in middle_row
            elif middle_row[0] > target:
                end_row = middle_row_i - 1
            else:
                start_row = middle_row_i + 1
        return False
