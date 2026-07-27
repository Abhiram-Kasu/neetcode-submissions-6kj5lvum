class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:

        graph = defaultdict(list)
        for src, dst, time in times:
            graph[src].append((dst, time))

        heap = [(0, k)]
        dist = {}
        max_dist = 0

        while heap:
            curr_time, node = heapq.heappop(heap)
            if node in dist:
                continue

            dist[node] = curr_time
            max_dist = max(curr_time, max_dist)

            for neighbor, weight in graph[node]:
                if neighbor not in dist:
                    heapq.heappush(heap, (curr_time + weight, neighbor))

        if len(dist) != n:
            return -1

        return max_dist





        