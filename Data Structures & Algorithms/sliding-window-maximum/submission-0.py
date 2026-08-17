class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        pq = []
        res = []

        for i in range(k):
            heapq.heappush(pq, (-nums[i], i))
        
        res.append(-pq[0][0])

        for i in range(k, len(nums)):
            heapq.heappush(pq, (-nums[i], i))

            while (i - pq[0][1] + 1) > k:
                heapq.heappop(pq)
            
            res.append(-pq[0][0])
        
        return res