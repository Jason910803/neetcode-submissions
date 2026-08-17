from collections import Counter
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # {num: freq, ...}
        # count = Counter(nums)
        # min_heap = []

        # for num, freq in count.items():
        #     heapq.heappush(min_heap, (freq, num))
        #     if len(min_heap) > k:
        #         heapq.heappop(min_heap)
        
        # return [num for freq, num in min_heap]
        
        # Time: O(NlogK), Space: O(N + K)

        # bucket sort
        count = Counter(nums)
        freq_buckets = [[] for _ in range(len(nums) + 1)]

        for num, freq in count.items():
            freq_buckets[freq].append(num)
        
        res = []
        for i in range(len(nums), 0, -1):
            for num in freq_buckets[i]:
                res.append(num)
                if len(res) == k:
                    return res
        
        return res