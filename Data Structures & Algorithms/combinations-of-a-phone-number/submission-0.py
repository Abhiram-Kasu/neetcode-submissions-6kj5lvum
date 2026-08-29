class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        res = []

        m = {
            '2': ['a','b','c'],
            '3': ['d','e','f'],
            '4': ['g','h','i'],
            '5': ['j','k','l'],
            '6': ['m','n','o'],
            '7': ['p','q','r', 's'],
            '8': ['t','u','v'],
            '9': ['w','x','y', 'z'],
        }

        def dfs(cur_ptr, cur):
            if cur_ptr == len(digits):
                if cur:
                    res.append(cur)
                return
            for letter in m[digits[cur_ptr]]:
                dfs(cur_ptr + 1, cur + letter)
        dfs(0, "")
        return res