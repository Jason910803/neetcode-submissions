class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # num -> freq
        count = Counter(nums)
        print(count)
        sorted_item = sorted(count.items(), key=lambda x: x[1], reverse=True)

        return [num for num, freq in sorted_item[:k]]