class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        max_len = 1
        l,r = 0,1
        curr = set([s[0]])
        curr_len = 1

        while r < len(s):
            # try to increase size of window
            cand = s[r]
            if cand in curr:
                while cand in curr:
                    curr.remove(s[l])
                    curr_len -=1
                    l += 1
                
                curr.add(cand)
                curr_len +=1

            else: 
                curr_len +=1
                curr.add(cand)
            max_len = max(max_len, curr_len)
            r += 1
        return max_len



        