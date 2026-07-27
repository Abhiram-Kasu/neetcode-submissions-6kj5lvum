class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def tryTransform(start, end):
            diff = 0
            for s,e in zip(start,end):
                if s != e:
                    diff +=1
            return diff == 1

        queue = deque([(beginWord, 1)])
        visited = {beginWord}

        while queue:
            curr, dist = queue.popleft()

            if curr == endWord:
                return dist

            for word in wordList:
                if word not in visited and tryTransform(curr, word):
                    visited.add(word)
                    queue.append((word, dist + 1))

        return 0




        
